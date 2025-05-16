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
    namespace notification {
        class CustomNotification {
        public:
            CustomNotification();
            ~CustomNotification();

            // 通知システムの初期化
            bool initialize(const std::string& config_path);
            
            // 通知の作成
            void createNotification(const std::string& title, const std::string& message, const std::string& type);
            
            // 通知の表示
            void showNotification();
            
            // 通知の非表示
            void hideNotification();
            
            // 通知設定の更新
            void updateNotificationSettings();
            
            // 通知フィルターの設定
            void setNotificationFilter(const std::string& filter);
            
            // 通知優先度の設定
            void setNotificationPriority(int priority);
            
            // 通知サウンドの設定
            void setNotificationSound(const std::string& sound_path);
            
            // 通知アニメーションの設定
            void setNotificationAnimation(const std::string& animation);
            
            // 通知のカスタマイズ
            void customizeNotification(const nlohmann::json& customization);
            
            // 通知履歴の取得
            std::vector<std::string> getNotificationHistory();
            
            // 通知設定の保存
            void saveNotificationSettings();
            
            // 通知設定の読み込み
            void loadNotificationSettings();
            
        private:
            struct Notification {
                std::string title;
                std::string message;
                std::string type;
                int priority;
                std::chrono::steady_clock::time_point timestamp;
            };

            std::vector<Notification> notifications_;
            std::mutex notifications_mutex_;
            std::thread notification_thread_;
            bool is_running_ = false;
            std::string current_filter_;
            int current_priority_ = 1;
            std::string sound_path_;
            std::string animation_;

            void notificationLoop();
            void processNotifications();
            void applyCustomization();
            void playSound();
            void animateNotification();
        };
    }
}
