#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <nlohmann/json.hpp>

namespace snake {
    namespace security {
        class SecurityMonitor {
        public:
            SecurityMonitor();
            ~SecurityMonitor();

            // セキュリティ監視の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの脅威検知
            void startAiThreatDetection();
            
            // リアルタイムセキュリティ監視
            void startRealtimeMonitoring();
            
            // セキュリティポリシー自動更新
            void autoUpdatePolicies();
            
            // セキュリティ更新自動適用
            void autoApplyUpdates();
            
            // セキュリティメトリクスの取得
            nlohmann::json getSecurityMetrics();
            
            // 監視設定の保存
            void saveMonitoringSettings();
            
            // 監視設定の読み込み
            void loadMonitoringSettings();
            
        private:
            struct SecurityMetrics {
                float threat_level;
                float policy_compliance;
                float update_status;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct Threat {
                std::string type;
                std::string description;
                float severity;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<SecurityMetrics> metrics_;
            std::vector<Threat> threats_;
            std::mutex metrics_mutex_;
            std::mutex threats_mutex_;
            std::thread monitoring_thread_;
            std::thread ai_thread_;
            bool is_running_ = false;
            bool is_ai_running_ = false;

            void monitoringLoop();
            void aiDetectionLoop();
            void processMetrics();
            void detectThreats();
            void autoUpdate();
            void saveState();
        };
    }
}
