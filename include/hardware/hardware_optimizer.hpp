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
    namespace hardware {
        class HardwareOptimizer {
        public:
            HardwareOptimizer();
            ~HardwareOptimizer();

            // ハードウェア最適化の初期化
            bool initialize(const std::string& config_path);
            
            // CPUキャッシュ最適化
            void optimizeCpuCache();
            
            // GPUメモリ管理
            void manageGpuMemory();
            
            // ストレージI/O最適化
            void optimizeStorageIO();
            

            
            // ハードウェアメトリクスの取得
            nlohmann::json getHardwareMetrics();
            
            // 最適化提案の生成
            std::vector<std::string> generateOptimizationSuggestions();
            
            // 最適化設定の保存
            void saveOptimizationSettings();
            
            // 最適化設定の読み込み
            void loadOptimizationSettings();
            
        private:
            struct HardwareMetrics {
                float cpu_cache_hit_rate;
                float gpu_memory_usage;
                float storage_io_throughput;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct OptimizationSuggestion {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<HardwareMetrics> metrics_;
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
