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
        enum class UIComponent {
            DASHBOARD,
            GPU_INFO,
            NETWORK_INFO,
            OPTIMIZATION_INFO,
            SECURITY_INFO,
            PERFORMANCE_CHART,
            SYSTEM_STATUS
        };

        struct UIConfig {
            bool dark_mode;
            float font_size;
            ImVec2 window_size;
            ImVec2 window_pos;
            std::string theme;
        };

        class EnhancedUI {
        public:
            EnhancedUI();
            ~EnhancedUI();

            // UIの初期化
            bool initialize(const UIConfig& config);
            
            // UIの描画
            void render();
            
            // UIコンポーネントの設定
            void setGpuInfo(const std::vector<std::string>& info);
            void setNetworkInfo(const std::vector<std::string>& info);
            void setOptimizationInfo(const std::vector<std::string>& info);
            void setSecurityInfo(const std::vector<std::string>& info);
            void setPerformanceData(const nlohmann::json& data);
            void setSystemStatus(const std::string& status);
            
            // UIイベントの処理
            bool handleEvents();
            
            // UI設定の更新
            bool updateConfig(const UIConfig& new_config);
            
            // UIメトリクスの収集
            nlohmann::json collectUIMetrics();
            
            // UI状態の取得
            bool isInitialized() const;
            bool isDarkMode() const;
            float getFontSize() const;
            ImVec2 getWindowSize() const;
            ImVec2 getWindowPos() const;
            
            // UIコンポーネントの有効/無効
            void enableComponent(UIComponent component);
            void disableComponent(UIComponent component);
            bool isComponentEnabled(UIComponent component) const;

        private:
            UIConfig config_;
            std::map<UIComponent, bool> components_;
            mutable std::mutex mutex_;
        };

        // UIコンポーネントの文字列化
        std::string uiComponentToString(UIComponent component);
    }
}
