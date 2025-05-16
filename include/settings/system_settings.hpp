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
        class SystemSettings {
        public:
            SystemSettings();
            ~SystemSettings();

            // システム設定の初期化
            bool initialize(const std::string& config_path);
            
            // カスタム設定
            void customizeSettings();
            
            // デフォルト設定
            void restoreDefaultSettings();
            
            // システム設定
            void configureSystem();
            
            // ユーザー設定
            void configureUser();
            
            // 設定の保存
            void saveSettings();
            
            // 設定の読み込み
            void loadSettings();
            
        private:
            struct Setting {
                std::string name;
                std::string value;
                std::string type;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct SettingMetrics {
                float customization_score;
                float default_score;
                float system_score;
                float user_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<Setting> settings_;
            std::vector<SettingMetrics> metrics_;
            std::mutex settings_mutex_;
            std::mutex metrics_mutex_;
            std::thread settings_thread_;
            bool is_running_ = false;

            void settingsLoop();
            void processSettings();
            void saveState();
        };
    }
}
