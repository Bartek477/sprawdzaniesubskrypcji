// DataProcessor.h
#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>
#include <map>
#include <string>

class DataProcessor {
public:
    static std::vector<std::map<std::string, std::string>> processTransactions(const std::vector<std::map<std::string, std::string>>& transactions);
};

#endif // DATAPROCESSOR_H