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
        class AutoBackup {
        public:
            AutoBackup();
            ~AutoBackup();

            // 自動バックアップの初期化
            bool initialize(const std::string& config_path);
            
            // スケジュールバックアップの開始
            void startScheduledBackup();
            
            // スケジュールバックアップの停止
            void stopScheduledBackup();
            
            // インクリメンタルバックアップの開始
            void startIncrementalBackup();
            
            // インクリメンタルバックアップの停止
            void stopIncrementalBackup();
            
            // バックアップの自動検証
            bool verifyBackup();
            
            // バックアップ設定の更新
            void updateBackupSettings();
            
            // バックアップ履歴の取得
            std::vector<std::string> getBackupHistory();
            
            // バックアップ設定の保存
            void saveBackupSettings();
            
            // バックアップ設定の読み込み
            void loadBackupSettings();
            
        private:
            struct BackupInfo {
                std::string type;
                std::string path;
                std::chrono::steady_clock::time_point timestamp;
                bool verified;
            };

            std::vector<BackupInfo> backup_history_;
            std::mutex backup_mutex_;
            std::thread backup_thread_;
            bool is_running_ = false;
            std::chrono::steady_clock::time_point last_verification_;

            void backupLoop();
            void verifyBackupInternal();
            void processBackups();
            void saveState();
        };
    }
}
