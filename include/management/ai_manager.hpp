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
    namespace management {
        class AI_Manager {
        public:
            AI_Manager();
            ~AI_Manager();

            // AI管理の初期化
            bool initialize(const std::string& config_path);
            
            // AIベースの管理
            void manageWithAI();
            
            // マシンラーニング管理
            void manageWithML();
            
            // データドリブン管理
            void manageWithData();
            
            // イベント駆動型管理
            void manageWithEvents();
            
            // 管理結果の取得
            std::vector<std::string> getManagementResults();
            
            // 管理メトリクスの取得
            nlohmann::json getManagementMetrics();
            
            // 管理設定の保存
            void saveManagementSettings();
            
            // 管理設定の読み込み
            void loadManagementSettings();
            
        private:
            struct ManagementResult {
                std::string type;
                std::string description;
                float efficiency;
                float confidence;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ManagementMetrics {
                float ai_score;
                float ml_score;
                float data_score;
                float event_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ManagementResult> results_;
            std::vector<ManagementMetrics> metrics_;
            std::mutex results_mutex_;
            std::mutex metrics_mutex_;
            std::thread management_thread_;
            bool is_running_ = false;

            void managementLoop();
            void processResults();
            void performManagement();
            void saveState();
        };
    }
}
