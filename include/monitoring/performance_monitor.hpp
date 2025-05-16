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
    namespace monitoring {
        class PerformanceMonitor {
        public:
            PerformanceMonitor();
            ~PerformanceMonitor();

            // パフォーマンス監視の初期化
            bool initialize(const std::string& config_path);
            
            // メトリクスダッシュボードの開始
            void startMetricsDashboard();
            
            // メトリクスダッシュボードの停止
            void stopMetricsDashboard();
            
            // パフォーマンスボトルネックの検出
            std::vector<std::string> detectBottlenecks();
            
            // システム負荷の予測
            float predictSystemLoad();
            
            // パフォーマンスメトリクスの取得
            nlohmann::json getPerformanceMetrics();
            
            // パフォーマンス警告の設定
            void setPerformanceAlerts();
            
            // パフォーマンス最適化の提案
            std::vector<std::string> suggestOptimizations();
            
            // パフォーマンスデータの収集
            void collectPerformanceData();
            
            // パフォーマンスデータの保存
            void savePerformanceData();
            
            // パフォーマンスデータの読み込み
            void loadPerformanceData();
            
        private:
            struct PerformanceMetrics {
                float cpu_usage;
                float memory_usage;
                float gpu_usage;
                float disk_usage;
                float network_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct PerformanceAlert {
                std::string type;
                float threshold;
                std::chrono::steady_clock::time_point last_alert;
            };

            std::vector<PerformanceMetrics> metrics_history_;
            std::vector<PerformanceAlert> alerts_;
            std::mutex metrics_mutex_;
            std::mutex alerts_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;
            std::chrono::steady_clock::time_point last_prediction_;

            void monitoringLoop();
            void detectBottlenecksInternal();
            void predictLoad();
            void collectMetrics();
            void processAlerts();
        };
    }
}
