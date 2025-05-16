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
    namespace automation {
        class AI_Automation {
        public:
            AI_Automation();
            ~AI_Automation();

            // AI自動化の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの自動化
            void automateWithAI();
            
            // マシンラーニング自動化
            void automateWithML();
            
            // データドリブン自動化
            void automateWithData();
            
            // イベント駆動型自動化
            void automateWithEvents();
            
            // 自動化ログの取得
            std::vector<std::string> getAutomationLogs();
            
            // 自動化メトリクスの取得
            nlohmann::json getAutomationMetrics();
            
            // 自動化設定の保存
            void saveAutomationSettings();
            
            // 自動化設定の読み込み
            void loadAutomationSettings();
            
        private:
            struct AutomationEvent {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AutomationMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<AutomationEvent> events_;
            std::vector<AutomationMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread automation_thread_;
            bool is_running_ = false;

            void automationLoop();
            void processEvents();
            void performAutomation();
            void saveState();
        };
    }
}
