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
    namespace performance {
        class PerformanceEnhancer {
        public:
            PerformanceEnhancer();
            ~PerformanceEnhancer();

            // パフォーマンス最適化の初期化
            bool initialize(const std::string& config_path);
            
            // CPU使用率の最適化
            void optimizeCpuUsage();
            
            // メモリ使用率の最適化
            void optimizeMemoryUsage();
            
            // ストレージ使用率の最適化
            void optimizeStorageUsage();
            
            // リソース使用予測
            nlohmann::json predictResourceUsage();
            
            // 最適化設定の保存
            void saveOptimizationSettings();
            
            // 最適化設定の読み込み
            void loadOptimizationSettings();
            
        private:
            struct OptimizationMetrics {
                float cpu_usage;
                float memory_usage;
                float storage_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ResourcePrediction {
                std::string resource;
                float predicted_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<OptimizationMetrics> metrics_;
            std::vector<ResourcePrediction> predictions_;
            std::mutex metrics_mutex_;
            std::mutex predictions_mutex_;
            std::thread optimization_thread_;
            bool is_running_ = false;

            void optimizationLoop();
            void processMetrics();
            void generatePredictions();
            void saveState();
        };
    }
}
