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
        class AI_Analyzer {
        public:
            AI_Analyzer();
            ~AI_Analyzer();

            // AI分析の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの分析
            nlohmann::json analyzeWithAI();
            
            // マシンラーニング分析
            nlohmann::json analyzeWithML();
            
            // データドリブン分析
            nlohmann::json analyzeWithData();
            
            // イベント駆動型分析
            nlohmann::json analyzeWithEvents();
            
            // 分析結果の取得
            std::vector<std::string> getAnalysisResults();
            
            // 分析メトリクスの取得
            nlohmann::json getAnalysisMetrics();
            
            // 分析設定の保存
            void saveAnalysisSettings();
            
            // 分析設定の読み込み
            void loadAnalysisSettings();
            
        private:
            struct AnalysisResult {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AnalysisMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<AnalysisResult> results_;
            std::vector<AnalysisMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread analysis_thread_;
            bool is_running_ = false;

            void analysisLoop();
            void processResults();
            void performAnalysis();
            void saveState();
        };
    }
}
