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
    namespace backup {
        class SystemBackup {
        public:
            SystemBackup();
            ~SystemBackup();

            // システムバックアップの初期化
            bool initialize(const std::string& config_path);
            
            // データバックアップ
            void backupData();
            
            // システムバックアップ
            void backupSystem();
            
            // ハードウェアバックアップ
            void backupHardware();
            
            // クラウドバックアップ
            void backupToCloud();
            
            // バックアップログの取得
            std::vector<std::string> getBackupLogs();
            
            // バックアップメトリクスの取得
            nlohmann::json getBackupMetrics();
            
            // バックアップ設定の保存
            void saveBackupSettings();
            
            // バックアップ設定の読み込み
            void loadBackupSettings();
            
        private:
            struct BackupEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct BackupMetrics {
                float success_rate;
                float backup_time;
                int backups_performed;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<BackupEvent> events_;
            std::vector<BackupMetrics> metrics_;
            std::mutex events_mutex_;
            std::mutex metrics_mutex_;
            std::thread backup_thread_;
            bool is_running_ = false;

            void backupLoop();
            void processEvents();
            void performBackups();
            void saveState();
        };
    }
}
