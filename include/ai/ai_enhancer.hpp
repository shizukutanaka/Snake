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
        class AIEnhancer {
        public:
            AIEnhancer();
            ~AIEnhancer();

            // AI機能の初期化
            bool initialize(const std::string& model_path);
            
            // AIベースの予測
            nlohmann::json predict();
            
            // AIによる最適化
            void optimize();
            
            // AIによる自動化
            void automate();
            
            // AIによる分析
            nlohmann::json analyze();
            
            // AIモデルの更新
            void updateModel();
            
            // AI設定の保存
            void saveAISettings();
            
            // AI設定の読み込み
            void loadAISettings();
            
        private:
            struct Prediction {
                std::string type;
                float confidence;
                std::string description;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct Optimization {
                std::string action;
                float improvement;
                std::string description;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<Prediction> predictions_;
            std::vector<Optimization> optimizations_;
            std::mutex predictions_mutex_;
            std::mutex optimizations_mutex_;
            std::thread ai_thread_;
            TF_Graph* graph_ = nullptr;
            TF_Session* session_ = nullptr;
            bool is_running_ = false;

            void aiLoop();
            void processPredictions();
            void applyOptimizations();
            void updateModelInternal();
            void saveState();
        };
    }
}
