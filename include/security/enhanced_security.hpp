#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <mutex>
#include <chrono>
#include <thread>
#include <condition_variable>

namespace snake {
    namespace security {
        enum class SecurityLevel {
            LOW,
            MEDIUM,
            HIGH,
            CRITICAL
        };

        enum class SecurityEvent {
            FILE_ACCESS,
            NETWORK_ACCESS,
            PROCESS_CREATE,
            MEMORY_ACCESS,
            REGISTRY_ACCESS
        };

        struct SecurityEventInfo {
            SecurityEvent type;
            std::string description;
            SecurityLevel severity;
            std::chrono::system_clock::time_point timestamp;
            std::string source;
            std::string target;
        };

        class EnhancedSecurity {
        public:
            EnhancedSecurity();
            ~EnhancedSecurity();

            // セキュリティの初期化
            void initialize();
            
            // セキュリティモニタリング
            void startMonitoring();
            void stopMonitoring();
            bool isMonitoring() const;
            
            // セキュリティイベントの監視
            void monitorFileAccess();
            void monitorNetworkAccess();
            void monitorProcessCreation();
            void monitorMemoryAccess();
            void monitorRegistryAccess();
            
            // セキュリティイベントの取得
            std::vector<SecurityEventInfo> getEvents(SecurityLevel min_level = SecurityLevel::MEDIUM);
            SecurityEventInfo getLastEvent();
            
            // セキュリティポリシーの設定
            void setFileAccessPolicy(const std::string& policy);
            void setNetworkPolicy(const std::string& policy);
            void setProcessPolicy(const std::string& policy);
            void setMemoryPolicy(const std::string& policy);
            void setRegistryPolicy(const std::string& policy);
            
            // セキュリティイベントの応答
            void blockEvent(const SecurityEventInfo& event);
            void logEvent(const SecurityEventInfo& event);
            void notifyEvent(const SecurityEventInfo& event);

        private:
            void monitorEvents();
            void processEvent(const SecurityEventInfo& event);
            void updateSecurityLevel();

            std::thread monitor_thread_;
            std::atomic<bool> is_running_;
            std::mutex events_mutex_;
            std::vector<SecurityEventInfo> events_;
            SecurityLevel current_level_;
            std::chrono::milliseconds monitor_interval_;
        };

        // セキュリティレベルの文字列化
        std::string securityLevelToString(SecurityLevel level);
        std::string securityEventToString(SecurityEvent event);
    }
}
