// HTMLParser.cpp
#include "HTMLParser.h"

std::vector<std::map<std::string, std::string>> HTMLParser::parseHtml(const std::string& htmlContent) {
    py::scoped_interpreter guard{}; // Start the interpreter and keep it alive

    auto parse_html = py::module_::import("html_parser").attr("parse_html");
    auto result = parse_html(htmlContent).cast<std::vector<std::map<std::string, std::string>>>();
    return result;
}