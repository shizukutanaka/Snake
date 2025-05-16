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
    namespace extension {
        class AI_Extension {
        public:
            AI_Extension();
            ~AI_Extension();

            // AI拡張の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの拡張
            void extendWithAI();
            
            // マシンラーニング拡張
            void extendWithML();
            
            // データドリブン拡張
            void extendWithData();
            
            // イベント駆動型拡張
            void extendWithEvents();
            
            // 拡張結果の取得
            std::vector<std::string> getExtensionResults();
            
            // 拡張メトリクスの取得
            nlohmann::json getExtensionMetrics();
            
            // 拡張設定の保存
            void saveExtensionSettings();
            
            // 拡張設定の読み込み
            void loadExtensionSettings();
            
        private:
            struct ExtensionResult {
                std::string type;
                std::string description;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ExtensionMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ExtensionResult> results_;
            std::vector<ExtensionMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread extension_thread_;
            bool is_running_ = false;

            void extensionLoop();
            void processResults();
            void performExtension();
            void saveState();
        };
    }
}
