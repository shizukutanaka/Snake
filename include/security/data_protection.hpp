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
#include <openssl/evp.h>
#include <openssl/aes.h>

namespace snake {
    namespace security {
        class DataProtection {
        public:
            DataProtection();
            ~DataProtection();

            // データ保護の初期化
            bool initialize(const std::string& config_path);
            
            // データ暗号化強化
            bool encryptData(const std::string& input_path, const std::string& output_path, const std::string& key);
            
            // データ復号化強化
            bool decryptData(const std::string& input_path, const std::string& output_path, const std::string& key);
            
            // データ整合性チェック
            bool verifyDataIntegrity();
            
            // データ復旧自動化
            void autoRecovery();
            
            // データ保護設定の更新
            void updateProtectionSettings();
            
            // データ保護ログの取得
            std::vector<std::string> getProtectionLogs();
            
            // データ保護メトリクスの取得
            nlohmann::json getProtectionMetrics();
            
        private:
            struct ProtectionEvent {
                std::string type;
                std::string description;
                bool success;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<ProtectionEvent> events_;
            std::mutex events_mutex_;
            std::thread protection_thread_;
            EVP_CIPHER_CTX* encrypt_ctx_ = nullptr;
            EVP_CIPHER_CTX* decrypt_ctx_ = nullptr;
            bool is_running_ = false;

            void protectionLoop();
            void processEvents();
            void verifyIntegrity();
            void attemptRecovery();
        };
    }
}
