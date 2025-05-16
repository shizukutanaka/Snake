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
#include <tensorflow/c/c_api.h>

namespace snake {
    namespace ai {
        class AutoOptimization {
        public:
            AutoOptimization();
            ~AutoOptimization();

            // AI最適化の初期化
            bool initialize(const std::string& model_path);
            
            // パフォーマンスパターンの学習
            void learnPerformancePatterns();
            
            // リソース使用予測
            nlohmann::json predictResourceUsage();
            
            // システム負荷の自動調整
            void autoAdjustSystemLoad();
            
            // AIモデルの更新
            void updateModel();
            
            // 学習データの収集
            void collectLearningData();
            
            // 学習データの保存
            void saveLearningData();
            
            // 学習データの読み込み
            void loadLearningData();
            
            // 最適化提案の生成
            std::vector<std::string> generateOptimizationSuggestions();
            
        private:
            struct LearningData {
                nlohmann::json metrics;
                float performance_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct OptimizationSuggestion {
                std::string action;
                float confidence;
                std::string description;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<LearningData> learning_data_;
            std::vector<OptimizationSuggestion> suggestions_;
            std::mutex data_mutex_;
            std::mutex suggestions_mutex_;
            std::thread learning_thread_;
            std::thread optimization_thread_;
            TF_Graph* graph_ = nullptr;
            TF_Session* session_ = nullptr;
            bool is_running_ = false;

            void learningLoop();
            void optimizationLoop();
            void processLearningData();
            void generateSuggestions();
            void updateModelInternal();
        };
    }
}
