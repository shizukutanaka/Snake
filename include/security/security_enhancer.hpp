#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <nlohmann/json.hpp>

namespace snake {
    namespace security {
        enum class ThreatLevel {
            LOW,
            MEDIUM,
            HIGH,
            CRITICAL
        };

        enum class SecurityPolicy {
            FILE_ACCESS,
            NETWORK_ACCESS,
            PROCESS_CREATE,
            MEMORY_ACCESS,
            REGISTRY_ACCESS
        };

        struct ThreatInfo {
            std::string description;
            ThreatLevel severity;
            std::chrono::steady_clock::time_point timestamp;
            std::string source;
            std::string target;
        };

        class SecurityEnhancer {
        public:
            SecurityEnhancer();
            ~SecurityEnhancer();

            // セキュリティ強化の初期化
            bool initialize(const nlohmann::json& config);
            
            // セキュリティスキャン
            std::vector<ThreatInfo> scanSystem();
            
            // セキュリティポリシーの適用
            bool applyPolicy(SecurityPolicy policy, const std::string& rule);
            
            // セキュリティ脅威の対応
            void handleThreat(const ThreatInfo& threat);
            
            // セキュリティログの取得
            std::vector<ThreatInfo> getSecurityLogs(size_t limit = 100);
            
            // セキュリティメトリクスの収集
            nlohmann::json collectSecurityMetrics();
            
            // セキュリティ状態のチェック
            bool checkSecurityStatus();
            
            // セキュリティポリシーの更新
            bool updatePolicy(SecurityPolicy policy, const std::string& new_rule);
            
            // セキュリティイベントの監視開始
            void startMonitoring();
            
            // セキュリティイベントの監視停止
            void stopMonitoring();
            
            // ファイルシステムの強化
            void enhanceFileSystem();
            
            // ネットワークセキュリティの強化
            void enhanceNetworkSecurity();
            
            // プロセスセキュリティの強化
            void enhanceProcessSecurity();
            
            // メモリ保護の強化
            void enhanceMemoryProtection();
            
            // セキュリティ更新の自動チェック
            void checkSecurityUpdates();
            
            // セキュリティ更新の適用
            void applySecurityUpdates();
            
            // セキュリティ設定の保存
            void saveSecuritySettings();
            
            // セキュリティ設定の読み込み
            void loadSecuritySettings();
            
            // AIベースの脅威検知
            void detectThreatsUsingAI();
            
            // リアルタイム脅威対応
            void respondToThreats();
            
            // セキュリティポリシーの自動更新
            void autoUpdatePolicies();
            
            // セキュリティ設定の自動同期
            void autoSyncSettings();
            
            // セキュリティ更新の自動化
            void automateSecurityUpdates();
            
            // セキュリティ設定の最適化
            void optimizeSecuritySettings();

        private:
            std::map<SecurityPolicy, std::string> policies_;
            std::vector<ThreatInfo> threats_;
            bool is_monitoring_;
            mutable std::mutex mutex_;
            std::thread security_thread_;
            bool is_enhancing_ = false;

            void securityLoop();
            void enhanceSecurity();
            void checkUpdates();
            void applyUpdates();
            void detectThreats();
            void respondToThreatsInternal();
            void updatePolicies();
            void syncSettings();
            void optimizeSettings();
        };

        // セキュリティレベルの文字列化
        std::string threatLevelToString(ThreatLevel level);
        std::string securityPolicyToString(SecurityPolicy policy);
    }
}
