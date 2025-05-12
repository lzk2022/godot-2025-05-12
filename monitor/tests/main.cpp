// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
// #include "thirdparty/vld/vld.h"

#include "common/utils.h"

#include <windows.h>
#include <iostream>

void initialize() {
	SetConsoleOutputCP(CP_UTF8);
	utils::init_spdlog();
}

int main(int argc, char **argv) {
	initialize(); // 在所有测试之前进行初始化
	int result = 0;
	{
		doctest::Context context(argc, argv);
		result = context.run();
		// 尝试显式清理 context 状态
	} // context在这里显式析构，确保释放所有资源

	return result;
}
