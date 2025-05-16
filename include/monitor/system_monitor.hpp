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
    namespace monitor {
        class SystemMonitor {
        public:
            SystemMonitor();
            ~SystemMonitor();

            // システム監視の初期化
            bool initialize(const std::string& config_path);
            
            // リアルタイム監視
            void startRealtimeMonitoring();
            
            // パフォーマンス予測
            nlohmann::json predictPerformance();
            
            // システムトラブル自動検知
            void detectSystemIssues();
            
            // オートスケーリング
            void autoScaleResources();
            
            // 監視ログの取得
            std::vector<std::string> getMonitoringLogs();
            
            // 監視メトリクスの取得
            nlohmann::json getMonitoringMetrics();
            
            // 監視設定の保存
            void saveMonitoringSettings();
            
            // 監視設定の読み込み
            void loadMonitoringSettings();
            
        private:
            struct MonitoringEvent {
                std::string type;
                std::string description;
                bool severity;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct MonitoringMetrics {
                float cpu_usage;
                float memory_usage;
                float network_usage;
                float storage_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<MonitoringEvent> events_;
            std::vector<MonitoringMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;

            void monitoringLoop();
            void processEvents();
            void performMonitoring();
            void saveState();
        };
    }
}
