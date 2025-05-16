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
        class SystemPredictor {
        public:
            SystemPredictor();
            ~SystemPredictor();

            // システム予測の初期化
            bool initialize(const std::string& config_path);
            
            // パフォーマンス予測
            nlohmann::json predictPerformance();
            
            // システムトラブル予測
            nlohmann::json predictIssues();
            
            // リソース使用予測
            nlohmann::json predictResourceUsage();
            
            // システム更新予測
            nlohmann::json predictUpdates();
            
            // 予測結果の保存
            void savePredictionResults();
            
            // 予測結果の読み込み
            void loadPredictionResults();
            
        private:
            struct PredictionResult {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct PredictionMetrics {
                float performance_confidence;
                float issue_confidence;
                float resource_confidence;
                float update_confidence;
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
