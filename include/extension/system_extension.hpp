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
    namespace extension {
        class SystemExtension {
        public:
            SystemExtension();
            ~SystemExtension();

            // システム拡張の初期化
            bool initialize(const std::string& config_path);
            
            // クラウド拡張
            void extendCloud();
            
            // デバイス拡張
            void extendDevice();
            
            // データ拡張
            void extendData();
            
            // システム拡張
            void extendSystem();
            
            // 拡張ログの取得
            std::vector<std::string> getExtensionLogs();
            
            // 拡張メトリクスの取得
            nlohmann::json getExtensionMetrics();
            
            // 拡張設定の保存
            void saveExtensionSettings();
            
            // 拡張設定の読み込み
            void loadExtensionSettings();
            
        private:
            struct ExtensionEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ExtensionMetrics {
                float cloud_score;
                float device_score;
                float data_score;
                float system_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ExtensionEvent> events_;
            std::vector<ExtensionMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread extension_thread_;
            bool is_running_ = false;

            void extensionLoop();
            void processEvents();
            void performExtension();
            void saveState();
        };
    }
}
