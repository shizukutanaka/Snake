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
    namespace protection {
        class SystemProtection {
        public:
            SystemProtection();
            ~SystemProtection();

            // システム保護の初期化
            bool initialize(const std::string& config_path);
            
            // セキュリティ保護
            void protectSecurity();
            
            // データ保護
            void protectData();
            
            // ハードウェア保護
            void protectHardware();
            
            // ネットワーク保護
            void protectNetwork();
            
            // 保護ログの取得
            std::vector<std::string> getProtectionLogs();
            
            // 保護メトリクスの取得
            nlohmann::json getProtectionMetrics();
            
            // 保護設定の保存
            void saveProtectionSettings();
            
            // 保護設定の読み込み
            void loadProtectionSettings();
            
        private:
            struct ProtectionEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ProtectionMetrics {
                float security_score;
                float data_score;
                float hardware_score;
                float network_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ProtectionEvent> events_;
            std::vector<ProtectionMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread protection_thread_;
            bool is_running_ = false;

            void protectionLoop();
            void processEvents();
            void performProtection();
            void saveState();
        };
    }
}
