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
    namespace analysis {
        class AI_Advanced_Analyzer {
        public:
            AI_Advanced_Analyzer();
            ~AI_Advanced_Analyzer();

            // AI高度分析の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの高度分析
            nlohmann::json advancedAnalysisWithAI();
            
            // マシンラーニング高度分析
            nlohmann::json advancedAnalysisWithML();
            
            // データドリブン高度分析
            nlohmann::json advancedAnalysisWithData();
            
            // イベント駆動型高度分析
            nlohmann::json advancedAnalysisWithEvents();
            
            // 高度分析結果の取得
            std::vector<std::string> getAdvancedResults();
            
            // 高度分析メトリクスの取得
            nlohmann::json getAdvancedMetrics();
            
            // 高度分析設定の保存
            void saveAdvancedSettings();
            
            // 高度分析設定の読み込み
            void loadAdvancedSettings();
            
        private:
            struct AdvancedResult {
                std::string type;
                std::string description;
                float analysis;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AdvancedMetrics {
                float ai_analysis;
                float ml_analysis;
                float data_analysis;
                float event_analysis;
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
