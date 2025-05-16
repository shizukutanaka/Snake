#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <nlohmann/json.hpp>
#include <imgui.h>

namespace snake {
    namespace ui {
        class Dashboard {
        public:
            Dashboard();
            ~Dashboard();

            // ダッシュボードの初期化
            bool initialize(const std::string& config_path);
            
            // ダッシュボードのレンダリング
            void render();
            
            // データの更新
            void updateData(const nlohmann::json& data);
            
            // レイアウトの更新
            void updateLayout();
            
            // カスタムウィジェットの追加
            void addWidget(const std::string& name, const std::string& type);
            
            // ウィジェットの削除
            void removeWidget(const std::string& name);
            
            // ウィジェットの配置変更
            void moveWidget(const std::string& name, int x, int y);
            
            // テーマの変更
            void setTheme(const std::string& theme_name);
            
            // フォントサイズの変更
            void setFontSize(float size);
            
            // ダッシュボードの状態保存
            void saveState();
            
            // ダッシュボードの状態読み込み
            void loadState();
            
        private:
            struct Widget {
                std::string name;
                std::string type;
                ImVec2 position;
                ImVec2 size;
                bool visible;
            };

            std::map<std::string, Widget> widgets_;
            std::string current_theme_;
            float font_size_ = 14.0f;
            ImVec2 window_size_;
            std::mutex state_mutex_;

            void renderPerformanceChart();
            void renderSecurityPanel();
            void renderSystemInfo();
            void renderCustomWidgets();
        };
    }
}
