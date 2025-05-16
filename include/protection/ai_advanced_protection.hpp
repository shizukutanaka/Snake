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
    namespace protection {
        class AI_Advanced_Protection {
        public:
            AI_Advanced_Protection();
            ~AI_Advanced_Protection();

            // AI高度保護の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの高度保護
            void advancedProtectionWithAI();
            
            // マシンラーニング高度保護
            void advancedProtectionWithML();
            
            // データドリブン高度保護
            void advancedProtectionWithData();
            
            // イベント駆動型高度保護
            void advancedProtectionWithEvents();
            
            // 高度保護結果の取得
            std::vector<std::string> getAdvancedResults();
            
            // 高度保護メトリクスの取得
            nlohmann::json getAdvancedMetrics();
            
            // 高度保護設定の保存
            void saveAdvancedSettings();
            
            // 高度保護設定の読み込み
            void loadAdvancedSettings();
            
        private:
            struct AdvancedResult {
                std::string type;
                std::string description;
                float protection;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AdvancedMetrics {
                float ai_protection;
                float ml_protection;
                float data_protection;
                float event_protection;
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
