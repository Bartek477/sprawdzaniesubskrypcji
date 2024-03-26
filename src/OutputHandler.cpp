// OutputHandler.cpp
#include "OutputHandler.h"
#include <filesystem>
#include <stdexcept>

void OutputHandler::ensureOutputDirExists(const std::string& filepath) {
    std::filesystem::path pathObj(filepath);
    std::filesystem::path dirPath = pathObj.parent_path();

    // Check if the directory exists
    if (!dirPath.empty() && !std::filesystem::exists(dirPath)) {
        // Attempt to create the directory
        if (!std::filesystem::create_directories(dirPath)) {
            throw std::runtime_error("Failed to create directory: " + dirPath.string());
        }
    }
}