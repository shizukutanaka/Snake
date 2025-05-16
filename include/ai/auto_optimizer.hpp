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
    namespace ai {
        class AutoOptimizer {
        public:
            AutoOptimizer();
            ~AutoOptimizer();

            // AI最適化エンジンの初期化
            bool initialize(const std::string& model_path);
            
            // システム状態の分析
            nlohmann::json analyzeSystemState();
            
            // 最適化提案の生成
            std::vector<std::string> generateOptimizationSuggestions();
            
            // 自動最適化の開始
            void startOptimization();
            
            // 自動最適化の停止
            void stopOptimization();
            
            // パフォーマンス予測
            float predictPerformance(const nlohmann::json& metrics);
            
            // リソース使用率の予測
            float predictResourceUsage(const nlohmann::json& metrics);
            
            // システム状態の監視開始
            void startMonitoring();
            
            // システム状態の監視停止
            void stopMonitoring();
            
            // AIモデルの更新
            void updateModel(const std::string& new_model_path);
            
            // 学習データの収集
            void collectLearningData();
            
            // 学習データの保存
            void saveLearningData(const std::string& path);
            
        private:
            struct SystemMetrics {
                float cpu_usage;
                float memory_usage;
                float gpu_usage;
                float disk_usage;
                float network_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct OptimizationSuggestion {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<SystemMetrics> metrics_history_;
            std::vector<OptimizationSuggestion> suggestions_;
            std::mutex metrics_mutex_;
            std::mutex suggestions_mutex_;
            std::thread monitoring_thread_;
            std::thread optimization_thread_;
            bool is_running_ = false;
            bool is_optimizing_ = false;
            std::string model_path_;
            std::condition_variable cv_;

            void monitoringLoop();
            void optimizationLoop();
            void analyzeMetrics();
            void generateSuggestions();
            void updateModelInternal();
        };
    }
}
