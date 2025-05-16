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
        class SystemAnalyzer {
        public:
            SystemAnalyzer();
            ~SystemAnalyzer();

            // システム分析の初期化
            bool initialize(const std::string& config_path);
            
            // パフォーマンス分析
            nlohmann::json analyzePerformance();
            
            // セキュリティ分析
            nlohmann::json analyzeSecurity();
            
            // データ分析
            nlohmann::json analyzeData();
            
            // システムトレンド分析
            nlohmann::json analyzeTrends();
            
            // 分析結果の保存
            void saveAnalysisResults();
            
            // 分析結果の読み込み
            void loadAnalysisResults();
            
        private:
            struct AnalysisResult {
                std::string type;
                std::string description;
                float score;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AnalysisMetrics {
                float performance_score;
                float security_score;
                float data_score;
                float trend_score;
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
