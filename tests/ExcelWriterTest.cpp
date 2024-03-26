#include <gtest/gtest.h>
#include <fstream>
#include "ExcelWriter.h"

class ExcelWriterTest : public ::testing::Test {
protected:
    // Test fixture setup can go here
    ExcelWriterTest() {
        // Setup code, if needed
    }

    ~ExcelWriterTest() override {
        // Cleanup code, if needed
    }

    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(ExcelWriterTest, CreatesExcelFile) {
    // Prepare test data
    std::vector<std::map<std::string, std::string>> transactions = {
        {{"date", "2024-03-01"}, {"description", "Test Transaction 1"}, {"amount", "$1.00"}},
        {{"date", "2024-03-02"}, {"description", "Test Transaction 2"}, {"amount", "$2.00"}}
    };
    
    // Specify a test file path
    std::string filename = "test_transactions.xlsx";
    
    // Write transactions to an Excel file
    ExcelWriter::writeTransactionsToExcel(filename, transactions);
    
    // Check if the file is created
    std::ifstream file(filename);
    ASSERT_TRUE(file.good());
    
    // Basic check to ensure the file is not empty
    file.seekg(0, std::ios::end);  
    size_t size = file.tellg();
    ASSERT_GT(size, 0);
    
    // Cleanup
    file.close();
    std::remove(filename.c_str());
}
