#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <nlohmann/json.hpp>
#include <algorithm>

namespace snake {
    namespace analytics {
        enum class AnalysisType {
            PERFORMANCE,
            SECURITY,
            USAGE,
            PREDICTION,
            TRENDS
        };

        struct AnalysisResult {
            AnalysisType type;
            std::string description;
            float score;
            std::vector<std::string> recommendations;
            std::chrono::steady_clock::time_point timestamp;
        };

        class EnhancedAnalytics {
        public:
            EnhancedAnalytics();
            ~EnhancedAnalytics();

            // データ分析の初期化
            bool initialize();
            
            // パフォーマンス分析
            AnalysisResult analyzePerformance(
                const std::vector<float>& cpu_usage,
                const std::vector<float>& memory_usage,
                const std::vector<float>& gpu_usage
            );
            
            // セキュリティ分析
            AnalysisResult analyzeSecurity(
                const std::vector<float>& threat_scores
            );
            
            // 使用状況分析
            AnalysisResult analyzeUsage(
                const std::vector<float>& resource_usage,
                const std::vector<float>& network_usage
            );
            
            // 予測分析
            AnalysisResult analyzePrediction(
                const std::vector<float>& historical_data,
                size_t prediction_window
            );
            
            // トレンド分析
            AnalysisResult analyzeTrends(
                const std::vector<float>& data,
                const std::chrono::seconds& time_window
            );
            
            // 分析履歴の取得
            std::vector<AnalysisResult> getAnalysisHistory(size_t limit = 100);
            
            // 分析結果のエクスポート
            std::string exportAnalysisResults();
            
            // 分析モデルの更新
            bool updateModel(const std::string& model_path);
            
            // 分析メトリクスの収集
            nlohmann::json collectAnalyticsMetrics();

        private:
            AnalysisResult analyzeData(
                const std::vector<float>& data,
                AnalysisType type,
                const std::string& description
            );

            std::vector<AnalysisResult> analysis_history_;
            mutable std::mutex mutex_;
        };

        // 分析タイプの文字列化
        std::string analysisTypeToString(AnalysisType type);
    }
}
