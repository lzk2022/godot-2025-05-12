set(LIB_NAME thirdparty)

# 定义 common 库
project(${LIB_NAME})

# 遍历当前目录下的所有 .cpp 文件
file(GLOB_RECURSE SOURCES "*.cpp" ".c")

# 递归遍历当前目录下的所有 .h 文件
file(GLOB_RECURSE HEADERS "*.h" ".hpp")

# 要排除的目录
set(EXCLUDE_DIRS
)

# 要排除的文件列表
set(EXCLUDE_FILES
)

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_filter_sources_and_headers_by_dirs(SOURCES HEADERS "${EXCLUDE_DIRS}")
utils_filter_sources_and_headers_by_files(SOURCES HEADERS "${EXCLUDE_FILES}")
utils_create_source_groups(SOURCES HEADERS)

# 添加库源文件
add_library(${LIB_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)

# 添加编译定义
target_compile_definitions(${LIB_NAME} PUBLIC
    SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE # 添加 spdlog 的 trace 等级
)

# 链接库
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(${LIB_NAME} PRIVATE
)

set(macro_include ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME})

# 包含头文件目录
target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME}/
)