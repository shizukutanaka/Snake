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
        class SystemMonitor {
        public:
            SystemMonitor();
            ~SystemMonitor();

            // システム監視の初期化
            bool initialize(const std::string& config_path);
            
            // リアルタイムシステム監視
            void startRealtimeMonitoring();
            
            // パフォーマンス予測
            nlohmann::json predictPerformance();
            
            // システムトラブル自動検知
            void detectSystemIssues();
            
            // オートスケーリング
            void autoScaleResources();
            
            // システムメトリクスの取得
            nlohmann::json getSystemMetrics();
            
            // 監視設定の保存
            void saveMonitoringSettings();
            
            // 監視設定の読み込み
            void loadMonitoringSettings();
            
            // AIベースの予測
            void predictUsingAI();
            
            // リアルタイムトラブル対応
            void handleRealtimeIssues();
            
            // 監視設定の自動更新
            void autoUpdateSettings();
            
            // メトリクス分析
            void analyzeMetrics();
            
            // 監視設定の最適化
            void optimizeMonitoring();
            
        private:
            struct SystemMetrics {
                float cpu_usage;
                float memory_usage;
                float gpu_usage;
                float disk_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct Issue {
                std::string type;
                std::string description;
                float severity;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<SystemMetrics> metrics_;
            std::vector<Issue> issues_;
            std::mutex metrics_mutex_;
            std::mutex issues_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;

            void monitoringLoop();
            void processMetrics();
            void detectIssues();
            void autoScale();
            void saveState();
            void predictIssues();
            void handleIssues();
            void updateSettings();
            void analyzeData();
            void optimizeSettings();
        };
    }
}
