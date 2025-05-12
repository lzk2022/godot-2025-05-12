#include "utils.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <windows.h>
#include <filesystem>

namespace utils {
	void init_spdlog(const std::string &filename) {
		SetConsoleOutputCP(CP_UTF8);
		std::string filepath = utils::get_data_path() + filename;
		try {
			// 创建文件接收器
			auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filepath, false);

			// 创建控制台接收器
			auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

			// 设置控制台接收器的日志格式，启用颜色
			console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] [%s:%#] %v");

			// 创建多重接收器记录器
			std::vector<spdlog::sink_ptr> sinks{ file_sink, console_sink };
			auto						  logger = std::make_shared<spdlog::logger>("global_logger", sinks.begin(), sinks.end());

			// 设置日志等级
			logger->set_level(spdlog::level::trace);

			// 设置全局记录器
			spdlog::set_default_logger(logger);

			// 设置文件接收器的日志格式
			// file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");
			// 设置控制台接收器的日志格式，启用颜色
			file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] [%s:%#] %v");
		} catch (const spdlog::spdlog_ex &ex) {
			std::cerr << "Log initialization failed: " << ex.what() << std::endl;
		}
	}
	void cleanup() {
		spdlog::shutdown();
	}
	std::string get_data_path() {
		static std::string data_path;
		if (!data_path.empty()) return data_path;
		data_path = utils::get_current_path() + "\\data\\";
		if (std::filesystem::exists(data_path)) return data_path;
		SPDLOG_ASSERT(!std::filesystem::create_directories(data_path), "创建{}目录失败!", data_path);
		SPDLOG_INFO("创建目录:{}", data_path);
		return data_path;
	}

	std::string get_current_path() {
		static std::string current_path;
		if (!current_path.empty()) return current_path;

		char buffer[MAX_PATH];
		GetModuleFileNameA(NULL, buffer, MAX_PATH);
		std::string::size_type pos = std::string(buffer).find_last_of("\\/");
		current_path			   = std::string(buffer).substr(0, pos);
		return current_path;
	}
} //namespace utils
