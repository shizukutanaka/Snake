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
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

namespace snake {
    namespace remote {
        class AdvancedRemoteManager {
        public:
            AdvancedRemoteManager();
            ~AdvancedRemoteManager();

            // リモート管理の初期化
            bool initialize(const std::string& config_path);
            
            // サーバーの起動
            void startServer();
            
            // サーバーの停止
            void stopServer();
            
            // リモートコマンドの実行
            nlohmann::json executeRemoteCommand(const std::string& command);
            
            // リモートモニタリングの開始
            void startMonitoring();
            
            // リモートモニタリングの停止
            void stopMonitoring();
            
            // セキュア接続の設定
            void setSecureConnection(bool enabled);
            
            // 接続認証の設定
            void setAuthentication(const std::string& username, const std::string& password);
            
            // リモートイベントの通知
            void notifyRemoteEvent(const std::string& event);
            
            // リモートログの取得
            std::vector<std::string> getRemoteLogs();
            
        private:
            struct RemoteClient {
                std::string id;
                std::string ip;
                std::string username;
                std::chrono::steady_clock::time_point last_active;
            };

            std::vector<RemoteClient> clients_;
            std::mutex clients_mutex_;
            std::thread monitoring_thread_;
            bool is_running_ = false;
            bool secure_connection_ = true;
            std::string username_;
            std::string password_;
            websocketpp::server<websocketpp::config::asio_no_tls> server_;

            void handleConnection(websocketpp::connection_hdl hdl);
            void handleDisconnection(websocketpp::connection_hdl hdl);
            void handleMessage(websocketpp::connection_hdl hdl, websocketpp::server<websocketpp::config::asio_no_tls>::message_ptr msg);
            void monitoringLoop();
            void processRemoteCommands();
        };
    }
}
