#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <mutex>
#include <chrono>
#include <functional>
#include <nlohmann/json.hpp>

namespace snake {
    namespace cloud {
        enum class CloudProvider {
            AWS,
            AZURE,
            GCP,
            ALIBABA_CLOUD
        };

        enum class CloudServiceType {
            STORAGE,
            COMPUTE,
            DATABASE,
            AI,
            SECURITY,
            ANALYTICS
        };

        struct CloudConfig {
            CloudProvider provider;
            std::string endpoint;
            std::string access_key;
            std::string secret_key;
            std::string region;
        };

        class CloudService {
        public:
            CloudService();
            ~CloudService();

            // クラウドサービスの初期化
            bool initialize(const CloudConfig& config);
            
            // クラウドストレージ
            bool uploadFile(const std::string& local_path, const std::string& remote_path);
            bool downloadFile(const std::string& remote_path, const std::string& local_path);
            bool deleteFile(const std::string& remote_path);
            bool listFiles(const std::string& prefix, std::vector<std::string>& files);
            
            // クラウドコンピューティング
            bool startInstance(const std::string& instance_id);
            bool stopInstance(const std::string& instance_id);
            bool scaleInstance(const std::string& instance_id, int cpu, int memory);
            
            // データベース
            bool backupDatabase(const std::string& db_name, const std::string& backup_name);
            bool restoreDatabase(const std::string& db_name, const std::string& backup_name);
            
            // AIサービス
            std::string predict(const std::string& model_name, const nlohmann::json& data);
            std::string analyze(const std::string& analysis_type, const nlohmann::json& data);
            
            // セキュリティ
            bool scanResource(const std::string& resource_id);
            bool applySecurityPolicy(const std::string& policy_name);
            
            // アナリティクス
            nlohmann::json queryAnalytics(const std::string& query);
            bool exportAnalytics(const std::string& export_type, const std::string& destination);
            
            // クラウドサービスの設定
            void setProvider(CloudProvider provider);
            void setEndpoint(const std::string& endpoint);
            void setCredentials(const std::string& access_key, const std::string& secret_key);
            void setRegion(const std::string& region);
            
            // クラウドサービスの状態
            bool isInitialized() const;
            bool isOnline() const;
            std::string getStatus() const;

        private:
            CloudProvider provider_;
            std::string endpoint_;
            std::string access_key_;
            std::string secret_key_;
            std::string region_;
            bool initialized_;
            bool online_;
            std::string status_;
            mutable std::mutex mutex_;
        };

        // クラウドプロバイダーの文字列化
        std::string cloudProviderToString(CloudProvider provider);
        std::string cloudServiceTypeToString(CloudServiceType type);
    }
}
