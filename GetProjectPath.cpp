#include "GetProjectPath.hpp"
#include <filesystem>

namespace fs = std::filesystem;

std::string getProjectPath() {
	return fs::current_path().string();
}

std::string getModelPath(std::string model) {
	return getProjectPath() + "\\Models" + model;
}
