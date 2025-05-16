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
        class AI_Enhanced_Protection {
        public:
            AI_Enhanced_Protection();
            ~AI_Enhanced_Protection();

            // AI強化保護の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの保護強化
            void enhanceProtectionWithAI();
            
            // マシンラーニング保護強化
            void enhanceProtectionWithML();
            
            // データドリブン保護強化
            void enhanceProtectionWithData();
            
            // イベント駆動型保護強化
            void enhanceProtectionWithEvents();
            
            // 保護強化結果の取得
            std::vector<std::string> getEnhancedResults();
            
            // 保護強化メトリクスの取得
            nlohmann::json getEnhancedMetrics();
            
            // 保護強化設定の保存
            void saveEnhancedSettings();
            
            // 保護強化設定の読み込み
            void loadEnhancedSettings();
            
        private:
            struct EnhancedResult {
                std::string type;
                std::string description;
                float protection;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct EnhancedMetrics {
                float ai_protection;
                float ml_protection;
                float data_protection;
                float event_protection;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<EnhancedResult> results_;
            std::vector<EnhancedMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread enhanced_thread_;
            bool is_running_ = false;

            void enhancedLoop();
            void processResults();
            void performEnhancement();
            void saveState();
        };
    }
}
