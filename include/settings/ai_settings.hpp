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
        class AI_Settings {
        public:
            AI_Settings();
            ~AI_Settings();

            // AI設定の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの設定
            void configureWithAI();
            
            // マシンラーニング設定
            void configureWithML();
            
            // データドリブン設定
            void configureWithData();
            
            // イベント駆動型設定
            void configureWithEvents();
            
            // 設定ログの取得
            std::vector<std::string> getSettingsLogs();
            
            // 設定メトリクスの取得
            nlohmann::json getSettingsMetrics();
            
            // 設定の保存
            void saveSettings();
            
            // 設定の読み込み
            void loadSettings();
            
        private:
            struct SettingEvent {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct SettingMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<SettingEvent> events_;
            std::vector<SettingMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread settings_thread_;
            bool is_running_ = false;

            void settingsLoop();
            void processEvents();
            void performSettings();
            void saveState();
        };
    }
}
