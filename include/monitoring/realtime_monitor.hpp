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
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

namespace snake {
    namespace monitoring {
        class RealtimeMonitor {
        public:
            RealtimeMonitor();
            ~RealtimeMonitor();

            // リアルタイム監視の初期化
            bool initialize(const std::string& config_path);
            
            // メトリクスストリーミングの開始
            void startMetricsStreaming();
            
            // メトリクスストリーミングの停止
            void stopMetricsStreaming();
            
            // ダッシュボードの自動更新
            void enableAutoUpdate();
            
            // ダッシュボードの手動更新
            void manualUpdate();
            
            // カスタマイズ可能な監視アラート
            void setCustomAlerts();
            
            // リアルタイムメトリクスの取得
            nlohmann::json getRealtimeMetrics();
            
            // リアルタイムイベントの監視
            void monitorRealtimeEvents();
            
            // カスタム監視設定の保存
            void saveCustomSettings();
            
            // カスタム監視設定の読み込み
            void loadCustomSettings();
            
        private:
            struct RealtimeMetrics {
                float cpu_usage;
                float memory_usage;
                float gpu_usage;
                float disk_usage;
                float network_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct CustomAlert {
                std::string type;
                float threshold;
                std::chrono::steady_clock::time_point last_alert;
            };

            std::vector<RealtimeMetrics> metrics_;
            std::vector<CustomAlert> alerts_;
            std::mutex metrics_mutex_;
            std::mutex alerts_mutex_;
            std::thread monitoring_thread_;
            websocketpp::server<websocketpp::config::asio_no_tls> server_;
            bool is_running_ = false;
            std::chrono::steady_clock::time_point last_update_;

            void monitoringLoop();
            void processMetrics();
            void checkAlerts();
            void updateDashboard();
            void handleConnection(websocketpp::connection_hdl hdl);
            void handleMessage(websocketpp::connection_hdl hdl, websocketpp::server<websocketpp::config::asio_no_tls>::message_ptr msg);
        };
    }
}
