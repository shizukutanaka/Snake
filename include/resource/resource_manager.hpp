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
    namespace resource {
        class ResourceManager {
        public:
            ResourceManager();
            ~ResourceManager();

            // リソース管理の初期化
            bool initialize(const std::string& config_path);
            
            // メモリ管理
            void manageMemory();
            float getMemoryUsage() const;
            void optimizeMemoryUsage();
            
            // ディスク管理
            void manageDisk();
            float getDiskUsage() const;
            void optimizeDiskUsage();
            
            // ネットワーク管理
            void manageNetwork();
            float getNetworkUsage() const;
            void optimizeNetworkUsage();
            
            // リソースリーク検出
            bool detectResourceLeak();
            
            // リソース使用率の監視
            void startMonitoring();
            void stopMonitoring();
            
            // リソース最適化の実行
            void optimizeResources();
            
            // リソース使用状況の取得
            nlohmann::json getResourceUsage();
            
            // リソース使用状況の保存
            void saveResourceUsage();
            
            // リソース使用状況の読み込み
            void loadResourceUsage();
            
        private:
            struct ResourceMetrics {
                float memory_usage;
                float disk_usage;
                float network_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ResourceMetrics> metrics_history_;
            std::mutex metrics_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;
            std::chrono::steady_clock::time_point last_optimization_;

            void monitoringLoop();
            void optimizeLoop();
            void detectLeak();
            void collectMetrics();
        };
    }
}
