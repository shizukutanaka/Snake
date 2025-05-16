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
    namespace protection {
        class AI_Protection {
        public:
            AI_Protection();
            ~AI_Protection();

            // AI保護の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの保護
            void protectWithAI();
            
            // マシンラーニング保護
            void protectWithML();
            
            // データドリブン保護
            void protectWithData();
            
            // イベント駆動型保護
            void protectWithEvents();
            
            // 保護結果の取得
            std::vector<std::string> getProtectionResults();
            
            // 保護メトリクスの取得
            nlohmann::json getProtectionMetrics();
            
            // 保護設定の保存
            void saveProtectionSettings();
            
            // 保護設定の読み込み
            void loadProtectionSettings();
            
        private:
            struct ProtectionResult {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ProtectionMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ProtectionResult> results_;
            std::vector<ProtectionMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread protection_thread_;
            bool is_running_ = false;

            void protectionLoop();
            void processResults();
            void performProtection();
            void saveState();
        };
    }
}
