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
        class PerformanceOptimizer {
        public:
            PerformanceOptimizer();
            ~PerformanceOptimizer();

            // パフォーマンス最適化の初期化
            bool initialize(const std::string& config_path);
            
            // メモリ最適化
            void optimizeMemory();
            
            // CPU最適化
            void optimizeCPU();
            
            // GPU最適化
            void optimizeGPU();
            
            // ストレージ最適化
            void optimizeStorage();
            
            // ネットワーク最適化
            void optimizeNetwork();
            
            // システムパフォーマンスの監視
            void monitorSystemPerformance();
            
            // パフォーマンスメトリクスの取得
            nlohmann::json getPerformanceMetrics();
            
            // 最適化提案の生成
            std::vector<std::string> generateOptimizationSuggestions();
            
            // 最適化設定の保存
            void saveOptimizationSettings();
            
            // 最適化設定の読み込み
            void loadOptimizationSettings();
            
        private:
            struct PerformanceMetrics {
                float cpu_usage;
                float memory_usage;
                float gpu_usage;
                float disk_usage;
                float network_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct OptimizationSuggestion {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<PerformanceMetrics> metrics_;
            std::vector<OptimizationSuggestion> suggestions_;
            std::mutex metrics_mutex_;
            std::mutex suggestions_mutex_;
            std::thread optimization_thread_;
            bool is_running_ = false;

            void optimizationLoop();
            void processMetrics();
            void generateSuggestions();
            void saveState();
        };
    }
}
