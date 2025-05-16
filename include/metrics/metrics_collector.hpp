#pragma once

#include <string>
#include <map>
#include <memory>
#include <chrono>
#include <vector>
#include <functional>
#include <mutex>
#include <atomic>

namespace snake {
    namespace metrics {
        enum class MetricType {
            COUNTER,
            GAUGE,
            HISTOGRAM,
            SUMMARY
        };

        struct Metric {
            MetricType type;
            std::string name;
            std::string description;
            std::chrono::steady_clock::time_point last_update;
        };

        class MetricsCollector {
        public:
            MetricsCollector();
            ~MetricsCollector();

            // メトリクスの登録
            void registerMetric(const std::string& name, const std::string& description, MetricType type);
            
            // カウンターメトリクス
            void increment(const std::string& name);
            void decrement(const std::string& name);
            void set(const std::string& name, int64_t value);
            int64_t get(const std::string& name) const;
            
            // ヒストグラムメトリクス
            void observe(const std::string& name, double value);
            double getAverage(const std::string& name) const;
            double getQuantile(const std::string& name, double quantile) const;
            
            // メトリクスのエクスポート
            std::string exportMetrics() const;
            
            // メトリクスのリセット
            void reset(const std::string& name);
            void resetAll();

        private:
            struct Counter {
                std::atomic<int64_t> value;
                std::chrono::steady_clock::time_point last_update;
            };

            struct Histogram {
                std::vector<double> values;
                std::chrono::steady_clock::time_point last_update;
            };

            std::map<std::string, Metric> metrics_;
            std::map<std::string, std::unique_ptr<Counter>> counters_;
            std::map<std::string, std::unique_ptr<Histogram>> histograms_;
            mutable std::mutex mutex_;
        };

        // メトリクスタイプの文字列化
        std::string metricTypeToString(MetricType type);
    }
}
