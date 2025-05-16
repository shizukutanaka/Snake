#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <nlohmann/json.hpp>

namespace snake {
    namespace backup {
        enum class BackupType {
            FULL,
            INCREMENTAL,
            DIFFERENTIAL,
            SNAPSHOT
        };

        enum class BackupStatus {
            IDLE,
            RUNNING,
            COMPLETED,
            FAILED
        };

        struct BackupConfig {
            BackupType type;
            std::string backup_path;
            std::vector<std::string> include_paths;
            std::vector<std::string> exclude_paths;
            std::chrono::minutes interval;
            size_t max_backup_count;
            bool compress;
            bool encrypt;
        };

        struct BackupStatusInfo {
            BackupStatus status;
            std::chrono::steady_clock::time_point last_update;
            std::string last_error;
            size_t current_backup_size;
            size_t total_backup_size;
        };

        class EnhancedBackup {
        public:
            EnhancedBackup();
            ~EnhancedBackup();

            // バックアップの初期化
            bool initialize(const BackupConfig& config);
            
            // バックアップの実行
            bool createBackup(const std::string& backup_name);
            
            // バックアップのリスト取得
            std::vector<std::string> listBackups();
            
            // バックアップの削除
            bool deleteBackup(const std::string& backup_name);
            
            // バックアップの復元
            bool restoreBackup(const std::string& backup_name);
            
            // バックアップの検証
            bool verifyBackup(const std::string& backup_name);
            
            // バックアップのスケジュール
            void scheduleBackup();
            
            // バックアップのスケジュール停止
            void stopBackupSchedule();
            
            // バックアップ状態の取得
            BackupStatusInfo getStatus();
            
            // バックアップメトリクスの収集
            nlohmann::json collectBackupMetrics();
            
            // バックアップ履歴の取得
            std::vector<std::string> getBackupHistory(size_t limit = 100);
            
            // バックアップ設定の更新
            bool updateConfig(const BackupConfig& new_config);

        private:
            BackupConfig config_;
            BackupStatusInfo status_;
            bool is_scheduled_;
            mutable std::mutex mutex_;
        };

        // バックアップタイプの文字列化
        std::string backupTypeToString(BackupType type);
        std::string backupStatusToString(BackupStatus status);
    }
}
