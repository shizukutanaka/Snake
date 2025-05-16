#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <nlohmann/json.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

namespace snake {
    namespace remote {
        enum class RemoteCommand {
            SCAN,
            OPTIMIZE,
            BACKUP,
            RESTORE,
            UPDATE,
            RESTART
        };

        struct RemoteStatus {
            bool is_online;
            std::chrono::steady_clock::time_point last_update;
            std::string version;
            std::string status;
        };

        class RemoteEnhancer {
        public:
            RemoteEnhancer();
            ~RemoteEnhancer();

            // リモート管理の初期化
            bool initialize(const std::string& host, int port);
            
            // リモートコマンドの実行
            bool executeCommand(RemoteCommand command, const nlohmann::json& data = {});
            
            // リモートステータスの取得
            RemoteStatus getStatus() const;
            
            // リモートイベントの監視開始
            void startMonitoring();
            
            // リモートイベントの監視停止
            void stopMonitoring();
            
            // リモートイベントの処理
            void handleEvent(const nlohmann::json& event);
            
            // リモート通知の送信
            bool sendNotification(const std::string& message, const std::string& type);
            
            // リモートログの取得
            std::vector<nlohmann::json> getRemoteLogs(size_t limit = 100);
            
            // リモートメトリクスの収集
            nlohmann::json collectRemoteMetrics();

        private:
            std::string host_;
            int port_;
            RemoteStatus status_;
            bool is_monitoring_;
            mutable std::mutex mutex_;
        };

        // リモートコマンドの文字列化
        std::string remoteCommandToString(RemoteCommand command);
    }
}
