#pragma once

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace snake {
    namespace security {
        class RealtimeMonitor {
        public:
            RealtimeMonitor();
            ~RealtimeMonitor();

            // リアルタイム監視の初期化
            bool initialize();
            
            // モニタリング開始
            void startMonitoring();
            
            // モニタリング停止
            void stopMonitoring();
            
            // セキュリティイベントの取得
            std::vector<std::string> getSecurityEvents() const;
            
            // ファイルシステム監視の設定
            void setFileSystemMonitor(bool enabled);
            
            // ネットワーク監視の設定
            void setNetworkMonitor(bool enabled);
            
            // プロセス監視の設定
            void setProcessMonitor(bool enabled);
            
            // セキュリティポリシーの設定
            void setSecurityPolicy(const std::map<std::string, std::string>& policy);
            
            // セキュリティイベントの通知
            void notifySecurityEvent(const std::string& event);
            
            // セキュリティリスクの評価
            int evaluateSecurityRisk() const;
            
        private:
            struct SecurityEvent {
                std::string type;
                std::string description;
                std::chrono::steady_clock::time_point timestamp;
                int severity;
            };

            std::vector<SecurityEvent> events_;
            std::mutex events_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;
            bool file_monitor_ = true;
            bool network_monitor_ = true;
            bool process_monitor_ = true;
            std::map<std::string, std::string> security_policy_;

            void monitoringLoop();
            void processSecurityEvents();
            void evaluateRiskLevel();
        };
    }
}
