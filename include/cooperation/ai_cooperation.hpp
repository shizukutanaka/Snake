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
    namespace cooperation {
        class AI_Cooperation {
        public:
            AI_Cooperation();
            ~AI_Cooperation();

            // AI連携の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの連携
            void cooperateWithAI();
            
            // マシンラーニング連携
            void cooperateWithML();
            
            // データドリブン連携
            void cooperateWithData();
            
            // イベント駆動型連携
            void cooperateWithEvents();
            
            // 連携結果の取得
            std::vector<std::string> getCooperationResults();
            
            // 連携メトリクスの取得
            nlohmann::json getCooperationMetrics();
            
            // 連携設定の保存
            void saveCooperationSettings();
            
            // 連携設定の読み込み
            void loadCooperationSettings();
            
        private:
            struct CooperationResult {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct CooperationMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<CooperationResult> results_;
            std::vector<CooperationMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread cooperation_thread_;
            bool is_running_ = false;

            void cooperationLoop();
            void processResults();
            void performCooperation();
            void saveState();
        };
    }
}
