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
    namespace cooperation {
        class AI_Enhanced_Cooperation {
        public:
            AI_Enhanced_Cooperation();
            ~AI_Enhanced_Cooperation();

            // AI強化連携の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの連携強化
            void enhanceCooperationWithAI();
            
            // マシンラーニング連携強化
            void enhanceCooperationWithML();
            
            // データドリブン連携強化
            void enhanceCooperationWithData();
            
            // イベント駆動型連携強化
            void enhanceCooperationWithEvents();
            
            // 連携強化結果の取得
            std::vector<std::string> getEnhancedResults();
            
            // 連携強化メトリクスの取得
            nlohmann::json getEnhancedMetrics();
            
            // 連携強化設定の保存
            void saveEnhancedSettings();
            
            // 連携強化設定の読み込み
            void loadEnhancedSettings();
            
        private:
            struct EnhancedResult {
                std::string type;
                std::string description;
                float cooperation;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct EnhancedMetrics {
                float ai_cooperation;
                float ml_cooperation;
                float data_cooperation;
                float event_cooperation;
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
