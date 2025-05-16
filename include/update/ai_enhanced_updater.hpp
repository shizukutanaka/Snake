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
    namespace update {
        class AI_Enhanced_Updater {
        public:
            AI_Enhanced_Updater();
            ~AI_Enhanced_Updater();

            // AI強化更新の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの更新強化
            void enhanceUpdateWithAI();
            
            // マシンラーニング更新強化
            void enhanceUpdateWithML();
            
            // データドリブン更新強化
            void enhanceUpdateWithData();
            
            // イベント駆動型更新強化
            void enhanceUpdateWithEvents();
            
            // 更新強化結果の取得
            std::vector<std::string> getEnhancedResults();
            
            // 更新強化メトリクスの取得
            nlohmann::json getEnhancedMetrics();
            
            // 更新強化設定の保存
            void saveEnhancedSettings();
            
            // 更新強化設定の読み込み
            void loadEnhancedSettings();
            
        private:
            struct EnhancedResult {
                std::string type;
                std::string description;
                float update;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct EnhancedMetrics {
                float ai_update;
                float ml_update;
                float data_update;
                float event_update;
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
