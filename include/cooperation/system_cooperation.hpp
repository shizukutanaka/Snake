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
    namespace cooperation {
        class SystemCooperation {
        public:
            SystemCooperation();
            ~SystemCooperation();

            // システム連携の初期化
            bool initialize(const std::string& config_path);
            
            // クラウド連携
            void cooperateCloud();
            
            // デバイス連携
            void cooperateDevice();
            
            // データ連携
            void cooperateData();
            
            // システム連携
            void cooperateSystem();
            
            // 連携ログの取得
            std::vector<std::string> getCooperationLogs();
            
            // 連携メトリクスの取得
            nlohmann::json getCooperationMetrics();
            
            // 連携設定の保存
            void saveCooperationSettings();
            
            // 連携設定の読み込み
            void loadCooperationSettings();
            
        private:
            struct CooperationEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct CooperationMetrics {
                float cloud_score;
                float device_score;
                float data_score;
                float system_score;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<CooperationEvent> events_;
            std::vector<CooperationMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread cooperation_thread_;
            bool is_running_ = false;

            void cooperationLoop();
            void processEvents();
            void performCooperation();
            void saveState();
        };
    }
}
