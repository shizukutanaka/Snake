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
    namespace system {
        class SystemUpdater {
        public:
            SystemUpdater();
            ~SystemUpdater();

            // システムアップデーターの初期化
            bool initialize(const std::string& config_path);
            
            // 自動アップデートの開始
            void startAutoUpdate();
            
            // 自動アップデートの停止
            void stopAutoUpdate();
            
            // バージョン管理の開始
            void startVersionManagement();
            
            // バージョン管理の停止
            void stopVersionManagement();
            
            // コンフリクトの解決
            bool resolveConflicts();
            
            // アップデートのチェック
            bool checkForUpdates();
            
            // アップデートの実行
            bool performUpdate();
            
            // バージョン情報の取得
            nlohmann::json getVersionInfo();
            
            // コンフリクト情報の取得
            std::vector<std::string> getConflictInfo();
            
            // アップデート履歴の取得
            std::vector<std::string> getUpdateHistory();
            
            // アップデート設定の保存
            void saveUpdateSettings();
            
            // アップデート設定の読み込み
            void loadUpdateSettings();
            
        private:
            struct UpdateInfo {
                std::string version;
                std::string release_date;
                std::string description;
                std::vector<std::string> changes;
            };

            struct ConflictInfo {
                std::string component;
                std::string current_version;
                std::string new_version;
                std::string conflict_type;
            };

            std::vector<UpdateInfo> update_history_;
            std::vector<ConflictInfo> conflicts_;
            std::mutex update_mutex_;
            std::mutex conflict_mutex_;
            std::thread update_thread_;
            bool is_running_ = false;
            std::chrono::steady_clock::time_point last_check_;

            void updateLoop();
            void checkForConflicts();
            void resolveConflictsInternal();
            void processUpdates();
            void saveState();
        };
    }
}
