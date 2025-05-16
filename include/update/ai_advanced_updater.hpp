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
        class AI_Advanced_Updater {
        public:
            AI_Advanced_Updater();
            ~AI_Advanced_Updater();

            // AI高度更新の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの高度更新
            void advancedUpdateWithAI();
            
            // マシンラーニング高度更新
            void advancedUpdateWithML();
            
            // データドリブン高度更新
            void advancedUpdateWithData();
            
            // イベント駆動型高度更新
            void advancedUpdateWithEvents();
            
            // 高度更新結果の取得
            std::vector<std::string> getAdvancedResults();
            
            // 高度更新メトリクスの取得
            nlohmann::json getAdvancedMetrics();
            
            // 高度更新設定の保存
            void saveAdvancedSettings();
            
            // 高度更新設定の読み込み
            void loadAdvancedSettings();
            
        private:
            struct AdvancedResult {
                std::string type;
                std::string description;
                float update;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AdvancedMetrics {
                float ai_update;
                float ml_update;
                float data_update;
                float event_update;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<AdvancedResult> results_;
            std::vector<AdvancedMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread advanced_thread_;
            bool is_running_ = false;

            void advancedLoop();
            void processResults();
            void performAdvanced();
            void saveState();
        };
    }
}
