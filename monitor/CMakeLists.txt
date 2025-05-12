cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(monitor)

# 启用 Unicode 编译模式
# add_definitions(-DUNICODE -D_UNICODE)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 如果需要，指定文件的编码为 UTF-8
# add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

# MSVC 设置 UTF-8 编译选项
if(MSVC)
    add_compile_options(/utf-8)
    add_compile_options(/Zc:__cplusplus)

    # 禁用所有警告
    add_compile_options(/w)

    # 禁用编译器启动标识信息
    add_compile_options(/nologo)

    # 编译器无法处理过大的对象文件
    add_compile_options(/bigobj)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-w)
endif()

# 添加子目录
add_subdirectory(common)
add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(editor)
add_subdirectory(main)
add_subdirectory(modules)
add_subdirectory(platform)
add_subdirectory(scene)
add_subdirectory(servers)
add_subdirectory(tests)
add_subdirectory(thirdparty)
