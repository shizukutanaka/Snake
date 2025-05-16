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
    namespace integration {
        class SystemIntegration {
        public:
            SystemIntegration();
            ~SystemIntegration();

            // システム統合の初期化
            bool initialize(const std::string& config_path);
            
            // クラウド統合
            void integrateCloud();
            
            // デバイス統合
            void integrateDevice();
            
            // データ統合
            void integrateData();
            
            // システム統合
            void integrateSystem();
            
            // 統合ログの取得
            std::vector<std::string> getIntegrationLogs();
            
            // 統合メトリクスの取得
            nlohmann::json getIntegrationMetrics();
            
            // 統合設定の保存
            void saveIntegrationSettings();
            
            // 統合設定の読み込み
            void loadIntegrationSettings();
            
        private:
            struct IntegrationEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct IntegrationMetrics {
                float cloud_score;
                float device_score;
                float data_score;
                float system_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<IntegrationEvent> events_;
            std::vector<IntegrationMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread integration_thread_;
            bool is_running_ = false;

            void integrationLoop();
            void processEvents();
            void performIntegration();
            void saveState();
        };
    }
}
