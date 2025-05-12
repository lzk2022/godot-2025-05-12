#pragma once
#include <string>

namespace utils {
	void init_spdlog(const std::string &filename = "monitor.log");
	void cleanup();

	std::string get_data_path();
	std::string get_current_path();
} //namespace utils