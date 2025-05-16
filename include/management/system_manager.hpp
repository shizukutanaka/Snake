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
        class SystemManager {
        public:
            SystemManager();
            ~SystemManager();

            // システム管理の初期化
            bool initialize(const std::string& config_path);
            
            // リモート管理
            void manageRemote();
            
            // グループ管理
            void manageGroup();
            
            // デバイス管理
            void manageDevice();
            
            // ユーザー管理
            void manageUser();
            
            // 管理ログの取得
            std::vector<std::string> getManagementLogs();
            
            // 管理メトリクスの取得
            nlohmann::json getManagementMetrics();
            
            // 管理設定の保存
            void saveManagementSettings();
            
            // 管理設定の読み込み
            void loadManagementSettings();
            
        private:
            struct ManagementEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ManagementMetrics {
                float remote_score;
                float group_score;
                float device_score;
                float user_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ManagementEvent> events_;
            std::vector<ManagementMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread management_thread_;
            bool is_running_ = false;

            void managementLoop();
            void processEvents();
            void performManagement();
            void saveState();
        };
    }
}
