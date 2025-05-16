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
    namespace update {
        class SystemUpdater {
        public:
            SystemUpdater();
            ~SystemUpdater();

            // システム更新の初期化
            bool initialize(const std::string& config_path);
            
            // システム更新自動化
            void autoUpdateSystem();
            
            // データ更新自動化
            void autoUpdateData();
            
            // セキュリティ更新自動化
            void autoUpdateSecurity();
            
            // バックグラウンド更新
            void backgroundUpdate();
            
            // 更新ログの取得
            std::vector<std::string> getUpdateLogs();
            
            // 更新メトリクスの取得
            nlohmann::json getUpdateMetrics();
            
            // 更新設定の保存
            void saveUpdateSettings();
            
            // 更新設定の読み込み
            void loadUpdateSettings();
            
        private:
            struct UpdateEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct UpdateMetrics {
                float update_rate;
                float update_time;
                int updates_performed;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<UpdateEvent> events_;
            std::vector<UpdateMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread update_thread_;
            bool is_running_ = false;

            void updateLoop();
            void processEvents();
            void performUpdates();
            void saveState();
        };
    }
}
