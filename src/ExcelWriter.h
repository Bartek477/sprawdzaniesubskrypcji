// ExcelWriter.h
#ifndef EXCELWRITER_H
#define EXCELWRITER_H

#include <vector>
#include <map>
#include <string>

class ExcelWriter {
public:
    static void writeTransactionsToExcel(const std::string& filename, const std::vector<std::map<std::string, std::string>>& transactions);
};