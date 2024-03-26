// InputHandler.cpp
#include "InputHandler.h"
#include <fstream>
#include <sstream>

std::string InputHandler::readHtmlFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}