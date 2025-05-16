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
    namespace extension {
        class AI_Enhanced_Extension {
        public:
            AI_Enhanced_Extension();
            ~AI_Enhanced_Extension();

            // AI強化拡張の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの拡張強化
            void enhanceExtensionWithAI();
            
            // マシンラーニング拡張強化
            void enhanceExtensionWithML();
            
            // データドリブン拡張強化
            void enhanceExtensionWithData();
            
            // イベント駆動型拡張強化
            void enhanceExtensionWithEvents();
            
            // 拡張強化結果の取得
            std::vector<std::string> getEnhancedResults();
            
            // 拡張強化メトリクスの取得
            nlohmann::json getEnhancedMetrics();
            
            // 拡張強化設定の保存
            void saveEnhancedSettings();
            
            // 拡張強化設定の読み込み
            void loadEnhancedSettings();
            
        private:
            struct EnhancedResult {
                std::string type;
                std::string description;
                float extension;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct EnhancedMetrics {
                float ai_extension;
                float ml_extension;
                float data_extension;
                float event_extension;
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
