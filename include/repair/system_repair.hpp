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
    namespace repair {
        class SystemRepair {
        public:
            SystemRepair();
            ~SystemRepair();

            // システム修復の初期化
            bool initialize(const std::string& config_path);
            
            // データ修復
            void repairData();
            
            // システム修復
            void repairSystem();
            
            // ハードウェア修復
            void repairHardware();
            
            // 自動修復
            void autoRepair();
            
            // 修復ログの取得
            std::vector<std::string> getRepairLogs();
            
            // 修復メトリクスの取得
            nlohmann::json getRepairMetrics();
            
            // 修復設定の保存
            void saveRepairSettings();
            
            // 修復設定の読み込み
            void loadRepairSettings();
            
        private:
            struct RepairEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct RepairMetrics {
                float success_rate;
                float repair_time;
                int repairs_performed;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<RepairEvent> events_;
            std::vector<RepairMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread repair_thread_;
            bool is_running_ = false;

            void repairLoop();
            void processEvents();
            void performRepairs();
            void saveState();
        };
    }
}
