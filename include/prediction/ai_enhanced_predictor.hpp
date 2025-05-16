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
    namespace prediction {
        class AI_Enhanced_Predictor {
        public:
            AI_Enhanced_Predictor();
            ~AI_Enhanced_Predictor();

            // AI強化予測の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの予測強化
            nlohmann::json enhancePredictionWithAI();
            
            // マシンラーニング予測強化
            nlohmann::json enhancePredictionWithML();
            
            // データドリブン予測強化
            nlohmann::json enhancePredictionWithData();
            
            // イベント駆動型予測強化
            nlohmann::json enhancePredictionWithEvents();
            
            // 予測強化結果の取得
            std::vector<std::string> getEnhancedResults();
            
            // 予測強化メトリクスの取得
            nlohmann::json getEnhancedMetrics();
            
            // 予測強化設定の保存
            void saveEnhancedSettings();
            
            // 予測強化設定の読み込み
            void loadEnhancedSettings();
            
        private:
            struct EnhancedResult {
                std::string type;
                std::string description;
                float accuracy;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct EnhancedMetrics {
                float ai_accuracy;
                float ml_accuracy;
                float data_accuracy;
                float event_accuracy;
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
