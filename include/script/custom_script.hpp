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
#include <lua.hpp>

namespace snake {
    namespace script {
        class CustomScript {
        public:
            CustomScript();
            ~CustomScript();

            // カスタムスクリプトの初期化
            bool initialize(const std::string& config_path);
            
            // スクリプトの実行
            bool executeScript(const std::string& script_path);
            
            // スクリプトの自動化
            void automateScript(const std::string& script_name);
            
            // スクリプト管理ダッシュボードの開始
            void startScriptDashboard();
            
            // スクリプト管理ダッシュボードの停止
            void stopScriptDashboard();
            
            // スクリプト設定の更新
            void updateScriptSettings();
            
            // スクリプトログの取得
            std::vector<std::string> getScriptLogs();
            
            // スクリプトメトリクスの取得
            nlohmann::json getScriptMetrics();
            
            // スクリプト設定の保存
            void saveScriptSettings();
            
            // スクリプト設定の読み込み
            void loadScriptSettings();
            
        private:
            struct Script {
                std::string name;
                std::string path;
                std::string type;
                std::chrono::steady_clock::time_point last_execution;
            };

            struct ScriptMetrics {
                std::string script_name;
                float execution_time;
                int memory_usage;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<Script> scripts_;
            std::vector<ScriptMetrics> metrics_;
            std::mutex scripts_mutex_;
            std::mutex metrics_mutex_;
            std::thread script_thread_;
            lua_State* L = nullptr;
            bool is_running_ = false;

            void scriptLoop();
            void processScripts();
            void collectMetrics();
            void saveState();
        };
    }
}
