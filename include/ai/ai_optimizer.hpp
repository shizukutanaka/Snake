#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <nlohmann/json.hpp>

namespace snake {
    namespace ai {
        enum class OptimizationType {
            CPU,
            MEMORY,
            GPU,
            STORAGE,
            NETWORK,
            ENERGY
        };

        struct OptimizationResult {
            OptimizationType type;
            float improvement;
            std::string description;
            std::chrono::steady_clock::time_point timestamp;
        };

        class AIOptimizer {
        public:
            AIOptimizer();
            ~AIOptimizer();

            // AI最適化の初期化
            bool initialize(const std::string& model_path);
            
            // パフォーマンス予測
            nlohmann::json predictPerformance(const nlohmann::json& data);
            
            // セキュリティ脅威予測
            nlohmann::json predictSecurityThreats(const nlohmann::json& data);
            
            // リソース最適化
            OptimizationResult optimizeResource(const std::string& resource_type, const nlohmann::json& data);
            
            // システム最適化
            std::vector<OptimizationResult> optimizeSystem(const nlohmann::json& system_data);
            
            // AIモデルの更新
            bool updateModel(const std::string& new_model_path);
            
            // モデルのメトリクス収集
            nlohmann::json collectModelMetrics();
            
            // 最適化履歴の取得
            std::vector<OptimizationResult> getOptimizationHistory(size_t limit = 100);
            
            // 最適化結果のエクスポート
            std::string exportOptimizationResults();

        private:
            std::string model_path_;
            std::map<std::string, OptimizationResult> optimization_history_;
            mutable std::mutex mutex_;
        };

        // AI最適化タイプの文字列化
        std::string optimizationTypeToString(OptimizationType type);
    }
}
