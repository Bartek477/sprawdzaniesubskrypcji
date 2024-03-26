// ExcelWriter.cpp
#include "ExcelWriter.h"
#include "xlsxwriter.h"

void ExcelWriter::writeTransactionsToExcel(const std::string& filename, const std::vector<std::map<std::string, std::string>>& transactions) {
    // Create a new workbook. Memory for the workbook is managed internally.
    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, nullptr); // Create a worksheet.

    // Titles for the columns
    std::vector<std::string> titles = {"Date", "Description", "Amount"};

    // Write column titles
    int column = 0;
    for (const auto& title : titles) {
        worksheet_write_string(worksheet, 0, column++, title.c_str(), nullptr);
    }

    // Write data rows
    int row = 1;
    for (const auto& transaction : transactions) {
        worksheet_write_string(worksheet, row, 0, transaction.at("date").c_str(), nullptr);
        worksheet_write_string(worksheet, row, 1, transaction.at("description").c_str(), nullptr);
        worksheet_write_string(worksheet, row, 2, transaction.at("amount").c_str(), nullptr);
        row++;
    }

    // Note: The workbook_close() function is required to free the memory for the workbook.
    workbook_close(workbook);
}