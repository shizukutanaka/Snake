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
        class AI_Monitor {
        public:
            AI_Monitor();
            ~AI_Monitor();

            // AI監視の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの監視
            void monitorWithAI();
            
            // マシンラーニング監視
            void monitorWithML();
            
            // データドリブン監視
            void monitorWithData();
            
            // イベント駆動型監視
            void monitorWithEvents();
            
            // 監視結果の取得
            std::vector<std::string> getMonitoringResults();
            
            // 監視メトリクスの取得
            nlohmann::json getMonitoringMetrics();
            
            // 監視設定の保存
            void saveMonitoringSettings();
            
            // 監視設定の読み込み
            void loadMonitoringSettings();
            
        private:
            struct MonitoringResult {
                std::string type;
                std::string description;
                float severity;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct MonitoringMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<MonitoringResult> results_;
            std::vector<MonitoringMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;

            void monitoringLoop();
            void processResults();
            void performMonitoring();
            void saveState();
        };
    }
}
