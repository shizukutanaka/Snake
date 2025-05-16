cmake_minimum_required(VERSION 3.10)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

# ヘッダーファイルのディレクトリを追加
include_directories(include)

# 新しいモジュールを追加
add_subdirectory(src/system)
add_subdirectory(src/profiling)
add_subdirectory(src/optimization)
add_subdirectory(src/ui)
add_subdirectory(src/security)
add_subdirectory(src/notification)
add_subdirectory(src/remote)
add_subdirectory(src/analytics)
add_subdirectory(src/ai)
add_subdirectory(src/backup)
add_subdirectory(src/error)
add_subdirectory(src/log)
add_subdirectory(src/resource)
add_subdirectory(src/cache)
add_subdirectory(src/metrics)
add_subdirectory(src/cloud)
add_subdirectory(src/performance)
add_subdirectory(src/remote)
add_subdirectory(src/testing)

# nlohmann/jsonのダウンロードとインストール
include(FetchContent)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

# ソースファイルの検索
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*/*.cpp
)

# メイン実行ファイルの追加
add_executable(snake main.cpp ${SOURCES})

# リンクするライブラリの設定
target_link_libraries(snake PRIVATE nlohmann_json::nlohmann_json)

# これはプラットフォーム固有のライブラリを追加する場所
