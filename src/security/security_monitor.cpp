#include "security/security_monitor.hpp"
#include "security/enhanced_security.hpp"
#include <filesystem>
#include <iostream>
#include <thread>

namespace snake {
    namespace security {

        SecurityMonitor::SecurityMonitor()
            : enhanced_security_(new EnhancedSecurity())
        {
        }

        SecurityMonitor::~SecurityMonitor()
        {
            delete enhanced_security_;
        }

        void SecurityMonitor::initialize()
        {
            enhanced_security_->initialize();
            enhanced_security_->startMonitoring();
            
            // セキュリティポリシーの設定
            enhanced_security_->setFileAccessPolicy("block_executable_from_temp");
            enhanced_security_->setNetworkPolicy("block_untrusted_outbound");
            enhanced_security_->setProcessPolicy("monitor_high_privilege");
            enhanced_security_->setMemoryPolicy("detect_memory_scan");
            enhanced_security_->setRegistryPolicy("monitor_critical_registry");
        }

        void SecurityMonitor::scan()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            
            // セキュリティイベントの取得
            auto events = enhanced_security_->getEvents();
            
            // イベントの処理
            for (const auto& event : events) {
                if (event.severity >= SecurityLevel::HIGH) {
                    // 高度な脅威の場合、即座にブロック
                    enhanced_security_->blockEvent(event);
                    
                    // 脅威情報を更新
                    ThreatInfo threat;
                    threat.description = event.description;
                    threat.severity = static_cast<float>(event.severity) / 3.0f;
                    threat.timestamp = event.timestamp;
                    
                    threats_.push_back(threat);
                    
                    // イベントをログに記録
                    enhanced_security_->logEvent(event);
                } else {
                    // 中程度の脅威の場合、監視を続ける
                    enhanced_security_->logEvent(event);
                }
            }
        }

        std::vector<ThreatInfo> SecurityMonitor::getThreats() const
        {
            std::lock_guard<std::mutex> lock(mutex_);
            return threats_;
        }

        bool SecurityMonitor::hasCriticalThreats() const
        {
            std::lock_guard<std::mutex> lock(mutex_);
            return std::any_of(threats_.begin(), threats_.end(),
                [](const ThreatInfo& threat) {
                    return threat.severity >= 0.8f;
                });
        }

        float SecurityMonitor::getThreatScore() const
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (threats_.empty()) return 0.0f;
            
            float sum = std::accumulate(threats_.begin(), threats_.end(), 0.0f,
                [](float a, const ThreatInfo& b) {
                    return a + b.severity;
                });
            
            return sum / threats_.size();
        }

    }
}
