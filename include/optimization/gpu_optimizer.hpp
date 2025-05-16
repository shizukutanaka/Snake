#pragma once

#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

namespace snake {
    namespace optimization {
        class GpuOptimizer {
        public:
            GpuOptimizer();
            ~GpuOptimizer();

            // GPU最適化の初期化
            bool initialize();
            
            // タスクをGPUキューに追加
            template<typename Func>
            void enqueueTask(Func&& task);
            
            // GPU使用率の監視開始
            void startMonitoring();
            
            // GPU使用率の取得
            float getGpuUsage() const;
            
            // GPUメモリ使用率の取得
            float getGpuMemoryUsage() const;
            
            // GPU温度の取得
            float getGpuTemperature() const;
            
            // GPUの最適化設定
            void setOptimizationLevel(int level);
            
            // GPUの省電力モード設定
            void setPowerSavingMode(bool enabled);
            
            // GPUの性能モード設定
            void setPerformanceMode(bool enabled);
            
        private:
            struct GpuMetrics {
                float usage;
                float memory_usage;
                float temperature;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<GpuMetrics> metrics_history_;
            std::mutex metrics_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;
            int optimization_level_ = 2;
            bool power_saving_mode_ = false;
            bool performance_mode_ = true;
            std::queue<std::function<void()>> task_queue_;
            std::mutex queue_mutex_;
            std::condition_variable queue_cv_;

            void monitoringLoop();
            void processTasks();
            void optimizeGpu();
        };
    }
}
