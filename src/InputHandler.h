// InputHandler.h
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>

class InputHandler {
public:
    static std::string readHtmlFile(const std::string& filePath);
};

#endif // INPUTHANDLER_H