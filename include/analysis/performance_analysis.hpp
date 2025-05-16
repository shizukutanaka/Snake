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
        class PerformanceAnalysis {
        public:
            PerformanceAnalysis();
            ~PerformanceAnalysis();

            // パフォーマンス分析の初期化
            bool initialize(const std::string& config_path);
            
            // データ収集
            void collectData();
            
            // パターン分析
            void analyzePatterns();
            
            // ボトルネック検出
            void detectBottlenecks();
            
            // 最適化提案
            void generateOptimizations();
            
            // 分析結果の取得
            nlohmann::json getAnalysisResults();
            
            // 分析設定の保存
            void saveAnalysisSettings();
            
            // 分析設定の読み込み
            void loadAnalysisSettings();
            
        private:
            struct AnalysisData {
                std::string metric;
                float value;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct Bottleneck {
                std::string type;
                float severity;
                std::string description;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<AnalysisData> data_;
            std::vector<Bottleneck> bottlenecks_;
            std::mutex data_mutex_;
            std::mutex bottlenecks_mutex_;
            std::thread analysis_thread_;
            bool is_running_ = false;

            void analysisLoop();
            void processData();
            void detectIssues();
            void generateOptimizationsInternal();
            void saveState();
        };
    }
}
