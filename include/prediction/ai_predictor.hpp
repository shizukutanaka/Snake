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
        class AI_Predictor {
        public:
            AI_Predictor();
            ~AI_Predictor();

            // AI予測の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの予測
            nlohmann::json predictWithAI();
            
            // マシンラーニング予測
            nlohmann::json predictWithML();
            
            // データドリブン予測
            nlohmann::json predictWithData();
            
            // イベント駆動型予測
            nlohmann::json predictWithEvents();
            
            // 予測結果の取得
            std::vector<std::string> getPredictionResults();
            
            // 予測メトリクスの取得
            nlohmann::json getPredictionMetrics();
            
            // 予測設定の保存
            void savePredictionSettings();
            
            // 予測設定の読み込み
            void loadPredictionSettings();
            
        private:
            struct PredictionResult {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct PredictionMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<PredictionResult> results_;
            std::vector<PredictionMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread prediction_thread_;
            bool is_running_ = false;

            void predictionLoop();
            void processResults();
            void performPredictions();
            void saveState();
        };
    }
}
