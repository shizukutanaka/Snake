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
    namespace prediction {
        class AI_Advanced_Predictor {
        public:
            AI_Advanced_Predictor();
            ~AI_Advanced_Predictor();

            // AI高度予測の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの高度予測
            nlohmann::json advancedPredictionWithAI();
            
            // マシンラーニング高度予測
            nlohmann::json advancedPredictionWithML();
            
            // データドリブン高度予測
            nlohmann::json advancedPredictionWithData();
            
            // イベント駆動型高度予測
            nlohmann::json advancedPredictionWithEvents();
            
            // 高度予測結果の取得
            std::vector<std::string> getAdvancedResults();
            
            // 高度予測メトリクスの取得
            nlohmann::json getAdvancedMetrics();
            
            // 高度予測設定の保存
            void saveAdvancedSettings();
            
            // 高度予測設定の読み込み
            void loadAdvancedSettings();
            
        private:
            struct AdvancedResult {
                std::string type;
                std::string description;
                float prediction;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AdvancedMetrics {
                float ai_prediction;
                float ml_prediction;
                float data_prediction;
                float event_prediction;
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
