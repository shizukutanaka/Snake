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
        class SystemOptimizer {
        public:
            SystemOptimizer();
            ~SystemOptimizer();

            // システム最適化の初期化
            bool initialize(const std::string& config_path);
            
            // CPU最適化
            void optimizeCPU();
            
            // メモリ最適化
            void optimizeMemory();
            
            // ストレージ最適化
            void optimizeStorage();
            
            // ネットワーク最適化
            void optimizeNetwork();
            
            // 最適化ログの取得
            std::vector<std::string> getOptimizationLogs();
            
            // 最適化メトリクスの取得
            nlohmann::json getOptimizationMetrics();
            
            // 最適化設定の保存
            void saveOptimizationSettings();
            
            // 最適化設定の読み込み
            void loadOptimizationSettings();
            
        private:
            struct OptimizationEvent {
                std::string type;
                std::string description;
                bool success;
                float improvement;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct OptimizationMetrics {
                float cpu_improvement;
                float memory_improvement;
                float storage_improvement;
                float network_improvement;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<OptimizationEvent> events_;
            std::vector<OptimizationMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread optimization_thread_;
            bool is_running_ = false;

            void optimizationLoop();
            void processEvents();
            void performOptimizations();
            void saveState();
        };
    }
}
