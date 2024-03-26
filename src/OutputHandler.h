// OutputHandler.h
#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include <string>
#include <filesystem>

class OutputHandler {
public:
    static void ensureOutputDirExists(const std::string& filepath);
};

#endif // OUTPUTHANDLER_H