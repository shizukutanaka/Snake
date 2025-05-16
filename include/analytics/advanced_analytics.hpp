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
    namespace analytics {
        class AdvancedAnalytics {
        public:
            AdvancedAnalytics();
            ~AdvancedAnalytics();

            // データ分析エンジンの初期化
            bool initialize(const std::string& config_path);
            
            // データ収集の開始
            void startDataCollection();
            
            // データ収集の停止
            void stopDataCollection();
            
            // パターン分析の実行
            std::vector<std::string> analyzePatterns();
            
            // 予測分析の実行
            nlohmann::json runPredictiveAnalysis();
            
            // アノマリ検出
            std::vector<std::string> detectAnomalies();
            
            // データの可視化
            void visualizeData();
            
            // レポートの生成
            void generateReport();
            
            // データのエクスポート
            void exportData(const std::string& format);
            
            // データのインポート
            void importData(const std::string& path);
            
            // カスタム分析の追加
            void addCustomAnalysis(const std::string& name, const std::string& type);
            
            // 分析結果の取得
            nlohmann::json getAnalysisResults();
            
        private:
            struct AnalysisData {
                std::string type;
                std::vector<float> values;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct AnalysisResult {
                std::string name;
                float score;
                std::string description;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<AnalysisData> data_;
            std::vector<AnalysisResult> results_;
            std::mutex data_mutex_;
            std::mutex results_mutex_;
            std::thread collection_thread_;
            std::thread analysis_thread_;
            bool is_running_ = false;
            bool is_analyzing_ = false;
            std::condition_variable cv_;

            void collectionLoop();
            void analysisLoop();
            void processAnalysis();
            void detectPatterns();
            void generatePredictions();
        };
    }
}
