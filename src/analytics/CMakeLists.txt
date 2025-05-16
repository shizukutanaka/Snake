add_library(analytics analytics_engine.cpp)

# ヘッダーファイルのディレクトリを追加
target_include_directories(analytics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# リンクするライブラリを追加
target_link_libraries(analytics PRIVATE nlohmann_json::nlohmann_json)
