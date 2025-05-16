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
        class AI_Integration {
        public:
            AI_Integration();
            ~AI_Integration();

            // AI統合の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの統合
            void integrateWithAI();
            
            // マシンラーニング統合
            void integrateWithML();
            
            // データドリブン統合
            void integrateWithData();
            
            // イベント駆動型統合
            void integrateWithEvents();
            
            // 統合結果の取得
            std::vector<std::string> getIntegrationResults();
            
            // 統合メトリクスの取得
            nlohmann::json getIntegrationMetrics();
            
            // 統合設定の保存
            void saveIntegrationSettings();
            
            // 統合設定の読み込み
            void loadIntegrationSettings();
            
        private:
            struct IntegrationResult {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct IntegrationMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<IntegrationResult> results_;
            std::vector<IntegrationMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread integration_thread_;
            bool is_running_ = false;

            void integrationLoop();
            void processResults();
            void performIntegration();
            void saveState();
        };
    }
}
