add_library(ai ai_engine.cpp)

# ヘッダーファイルのディレクトリを追加
target_include_directories(ai PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# リンクするライブラリを追加
target_link_libraries(ai PRIVATE nlohmann_json::nlohmann_json)
