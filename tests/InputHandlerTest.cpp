#include <gtest/gtest.h>
#include "InputHandler.h"
#include <fstream>

// Utility function to create a temporary HTML file for testing
void createTestHtmlFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}

// Test Fixture for setting up the HTML file
class InputHandlerTest : public ::testing::Test {
protected:
    std::string testFilePath = "test.html";
    std::string testContent = "<html><body><p>Hello, world!</p></body></html>";

    void SetUp() override {
        // Create a test HTML file before each test
        createTestHtmlFile(testFilePath, testContent);
    }

    void TearDown() override {
        // Cleanup: Remove the test file after each test
        std::remove(testFilePath.c_str());
    }
};

// Test case to verify the InputHandler can read the content of an HTML file
TEST_F(InputHandlerTest, ReadsHtmlFileCorrectly) {
    std::string content = InputHandler::readHtmlFile(testFilePath);
    ASSERT_EQ(content, testContent);
}