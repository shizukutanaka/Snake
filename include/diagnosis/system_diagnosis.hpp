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
    namespace diagnosis {
        class SystemDiagnosis {
        public:
            SystemDiagnosis();
            ~SystemDiagnosis();

            // システム診断の初期化
            bool initialize(const std::string& config_path);
            
            // ヘルスチェックの実行
            nlohmann::json performHealthCheck();
            
            // パフォーマンスボトルネックの分析
            std::vector<std::string> analyzeBottlenecks();
            
            // セキュリティリスクの評価
            int evaluateSecurityRisk();
            
            // システム状態の診断
            std::vector<std::string> diagnoseSystemState();
            
            // リソース使用状況の分析
            nlohmann::json analyzeResourceUsage();
            
            // システムログの分析
            std::vector<std::string> analyzeSystemLogs();
            
            // 診断結果の保存
            void saveDiagnosisResults();
            
            // 診断結果の読み込み
            void loadDiagnosisResults();
            
            // AIベースの診断
            void diagnoseUsingAI();
            
            // 診断スケジュールの最適化
            void optimizeDiagnosisSchedule();
            
            // 診断設定の自動更新
            void autoUpdateDiagnosisSettings();
            
            // 診断結果の分析
            void analyzeDiagnosisResults();
            
            // 診断設定の最適化
            void optimizeDiagnosisSettings();
            
        private:
            struct HealthCheck {
                std::string component;
                bool status;
                std::string message;
                std::chrono::steady_clock::time_point timestamp;
            };

            struct ResourceAnalysis {
                std::string type;
                float usage;
                float threshold;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<HealthCheck> health_checks_;
            std::vector<ResourceAnalysis> resource_analysis_;
            std::mutex checks_mutex_;
            std::mutex analysis_mutex_;
            std::thread diagnosis_thread_;
            bool is_running_ = false;

            void diagnosisLoop();
            void performChecks();
            void analyzeResources();
            void processLogs();
            void saveResults();
            void diagnoseWithAI();
            void optimizeSchedule();
            void updateSettings();
            void analyzeResults();
            void optimizeSettings();
        };
    }
}
