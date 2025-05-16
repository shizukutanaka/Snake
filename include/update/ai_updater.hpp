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
        class AI_Updater {
        public:
            AI_Updater();
            ~AI_Updater();

            // AI更新の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの更新
            void updateWithAI();
            
            // マシンラーニング更新
            void updateWithML();
            
            // データドリブン更新
            void updateWithData();
            
            // イベント駆動型更新
            void updateWithEvents();
            
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
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct UpdateMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
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
