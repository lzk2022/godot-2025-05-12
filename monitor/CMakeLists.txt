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

    # 强制设置 MSVC 的运行时库为静态链接的 Release 模式（/MT）
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:>")

    # 关闭迭代器调试
    add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)

    # 强制所有模式（包括Debug）使用 Release 运行时库
    foreach(flag_var
        CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
        if(${flag_var} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        endif()

        if(${flag_var} MATCHES "/MDd")
            string(REGEX REPLACE "/MDd" "/MT" ${flag_var} "${${flag_var}}")
        endif()

        if(${flag_var} MATCHES "/MTd")
            string(REGEX REPLACE "/MTd" "/MT" ${flag_var} "${${flag_var}}")
        endif()
    endforeach()
endif()

# 第一次去掉末尾的 monitor
get_filename_component(PARENT_DIR "${CMAKE_SOURCE_DIR}" DIRECTORY)
get_filename_component(GODOT_BASE_DIR "${PARENT_DIR}" DIRECTORY)

# set(macro_scons_thirdparty_include ${GODOT_BASE_DIR}/godot-4.4.1/godot-4.4.1)
# 设置为CACHE变量，全局可见
set(macro_scons_thirdparty_include "${GODOT_BASE_DIR}/godot-4.4.1/godot-4.4.1" CACHE PATH "Path to godot thirdparty directory")
set(macro_scons_thirdparty_modules ${macro_scons_thirdparty_include}/thirdparty)

# message("macro_scons_thirdparty_include: ${macro_scons_thirdparty_include}")
add_subdirectory(core)
add_subdirectory(${macro_scons_thirdparty_modules}/misc ${CMAKE_BINARY_DIR}/misc)
add_subdirectory(${macro_scons_thirdparty_modules}/clipper2 ${CMAKE_BINARY_DIR}/clipper2)
add_subdirectory(${macro_scons_thirdparty_modules}/brotli ${CMAKE_BINARY_DIR}/brotli)
add_subdirectory(${macro_scons_thirdparty_modules}/minizip ${CMAKE_BINARY_DIR}/minizip)
add_subdirectory(${macro_scons_thirdparty_modules}/zlib ${CMAKE_BINARY_DIR}/zlib)
add_subdirectory(${macro_scons_thirdparty_modules}/zstd ${CMAKE_BINARY_DIR}/zstd)

# servers
add_subdirectory(servers)
add_subdirectory(${macro_scons_thirdparty_modules}/amd-fsr2 ${CMAKE_BINARY_DIR}/amd-fsr2)
add_subdirectory(${macro_scons_thirdparty_modules}/spirv-reflect ${CMAKE_BINARY_DIR}/spirv-reflect)