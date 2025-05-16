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
#include <imgui.h>

namespace snake {
    namespace ui {
        class UserExperience {
        public:
            UserExperience();
            ~UserExperience();

            // ユーザー体験の初期化
            bool initialize(const std::string& config_path);
            
            // カスタムテーマの設定
            void setCustomTheme();
            
            // カスタムフォントの設定
            void setCustomFont();
            
            // カスタムウィジェットの追加
            void addCustomWidget();
            
            // インタラクティブなUI要素の追加
            void addInteractiveElements();
            
            // カスタムアニメーションの設定
            void setCustomAnimations();
            
            // カスタムサウンドの設定
            void setCustomSounds();
            
            // ユーザー設定の保存
            void saveUserSettings();
            
            // ユーザー設定の読み込み
            void loadUserSettings();
            
            // カスタムエフェクトの設定
            void setCustomEffects();
            
            // カスタムアニメーションの追加
            void addCustomAnimations();
            
            // インタラクティブUIの最適化
            void optimizeInteractiveUI();
            
            // カスタムウィジェットの最適化
            void optimizeCustomWidgets();
            
            // カスタムテーマの最適化
            void optimizeCustomThemes();
            
            // ユーザー設定の自動保存
            void autoSaveUserSettings();
            
            // ユーザー設定の同期
            void syncUserSettings();
            
            // AIベースのUI最適化
            void optimizeUIUsingAI();
            
            // UI要素の自動配置
            void autoArrangeUIElements();
            
            // カスタムエフェクトの最適化
            void optimizeCustomEffects();
            
            // インタラクティブUIの強化
            void enhanceInteractiveUI();
            
            // ユーザー設定の自動更新
            void autoUpdateUserSettings();
            
            // UI設定の最適化
            void optimizeUISettings();
            
        private:
            struct Theme {
                std::string name;
                ImVec4 primary_color;
                ImVec4 secondary_color;
                float font_size;
            };

            struct Widget {
                std::string name;
                std::string type;
                ImVec2 position;
                ImVec2 size;
                bool visible;
            };

            std::vector<Theme> themes_;
            std::vector<Widget> widgets_;
            std::mutex ui_mutex_;
            std::thread ui_thread_;
            std::thread animation_thread_;
            bool is_running_ = false;
            bool is_auto_saving_ = false;

            void animationLoop();
            void optimizeUI();
            void saveState();
            void syncSettings();
            void optimizeElements();
            void arrangeElements();
            void enhanceUI();
            void updateSettings();
            void optimizeSettings();

            void uiLoop();
            void processUI();
            void applyTheme();
            void applyAnimations();
            void applySounds();
        };
    }
}
