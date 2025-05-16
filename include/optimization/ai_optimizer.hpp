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
    namespace optimization {
        class AI_Optimizer {
        public:
            AI_Optimizer();
            ~AI_Optimizer();

            // AI最適化の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの最適化
            void optimizeWithAI();
            
            // マシンラーニング最適化
            void optimizeWithML();
            
            // データドリブン最適化
            void optimizeWithData();
            
            // イベント駆動型最適化
            void optimizeWithEvents();
            
            // 最適化結果の取得
            std::vector<std::string> getOptimizationResults();
            
            // 最適化メトリクスの取得
            nlohmann::json getOptimizationMetrics();
            
            // 最適化設定の保存
            void saveOptimizationSettings();
            
            // 最適化設定の読み込み
            void loadOptimizationSettings();
            
        private:
            struct OptimizationResult {
                std::string type;
                std::string description;
                float improvement;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct OptimizationMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<OptimizationResult> results_;
            std::vector<OptimizationMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread optimization_thread_;
            bool is_running_ = false;

            void optimizationLoop();
            void processResults();
            void performOptimization();
            void saveState();
        };
    }
}
