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
        class AI_Advanced_Automation {
        public:
            AI_Advanced_Automation();
            ~AI_Advanced_Automation();

            // AI高度自動化の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの高度自動化
            void advancedAutomationWithAI();
            
            // マシンラーニング高度自動化
            void advancedAutomationWithML();
            
            // データドリブン高度自動化
            void advancedAutomationWithData();
            
            // イベント駆動型高度自動化
            void advancedAutomationWithEvents();
            
            // 高度自動化結果の取得
            std::vector<std::string> getAdvancedResults();
            
            // 高度自動化メトリクスの取得
            nlohmann::json getAdvancedMetrics();
            
            // 高度自動化設定の保存
            void saveAdvancedSettings();
            
            // 高度自動化設定の読み込み
            void loadAdvancedSettings();
            
        private:
            struct AdvancedResult {
                std::string type;
                std::string description;
                float automation;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AdvancedMetrics {
                float ai_automation;
                float ml_automation;
                float data_automation;
                float event_automation;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<AdvancedResult> results_;
            std::vector<AdvancedMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread advanced_thread_;
            bool is_running_ = false;

            void advancedLoop();
            void processResults();
            void performAdvanced();
            void saveState();
        };
    }
}
