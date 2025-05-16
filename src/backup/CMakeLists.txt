add_library(backup backup_manager.cpp)

# ヘッダーファイルのディレクトリを追加
target_include_directories(backup PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# リンクするライブラリを追加
target_link_libraries(backup PRIVATE nlohmann_json::nlohmann_json)
