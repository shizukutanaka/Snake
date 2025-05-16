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
    namespace settings {
        class AI_Advanced_Settings {
        public:
            AI_Advanced_Settings();
            ~AI_Advanced_Settings();

            // AI高度設定の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの高度設定
            void advancedSettingsWithAI();
            
            // マシンラーニング高度設定
            void advancedSettingsWithML();
            
            // データドリブン高度設定
            void advancedSettingsWithData();
            
            // イベント駆動型高度設定
            void advancedSettingsWithEvents();
            
            // 高度設定結果の取得
            std::vector<std::string> getAdvancedResults();
            
            // 高度設定メトリクスの取得
            nlohmann::json getAdvancedMetrics();
            
            // 高度設定設定の保存
            void saveAdvancedSettings();
            
            // 高度設定設定の読み込み
            void loadAdvancedSettings();
            
        private:
            struct AdvancedResult {
                std::string type;
                std::string description;
                float settings;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AdvancedMetrics {
                float ai_settings;
                float ml_settings;
                float data_settings;
                float event_settings;
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
