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
#include <pugixml.hpp>

namespace snake {
    namespace report {
        class ReportGenerator {
        public:
            ReportGenerator();
            ~ReportGenerator();

            // レポートジェネレータの初期化
            bool initialize(const std::string& config_path);
            
            // カスタマイズ可能なレポートの生成
            void generateCustomReport();
            
            // レポートスケジュールの設定
            void setReportSchedule();
            
            // レポート配信の設定
            void configureReportDelivery();
            
            // レポートテンプレートの管理
            void manageReportTemplates();
            
            // レポートの保存
            void saveReport();
            
            // レポートの読み込み
            void loadReport();
            
            // レポート設定の保存
            void saveReportSettings();
            
            // レポート設定の読み込み
            void loadReportSettings();
            
        private:
            struct Report {
                std::string title;
                std::string type;
                std::chrono::steady_clock::time_point timestamp;
                std::string format;
            };

            struct ReportSchedule {
                std::string type;
                std::chrono::minutes interval;
                std::chrono::steady_clock::time_point last_run;
            };

            std::vector<Report> reports_;
            std::vector<ReportSchedule> schedules_;
            std::mutex reports_mutex_;
            std::mutex schedules_mutex_;
            std::thread report_thread_;
            bool is_running_ = false;

            void reportLoop();
            void generateReports();
            void deliverReports();
            void saveState();
        };
    }
}
