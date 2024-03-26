// HTMLParser.h
#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // To automatically convert C++ STL containers to Python types
#include <string>
#include <vector>
#include <map>

namespace py = pybind11;

class HTMLParser {
public:
    static std::vector<std::map<std::string, std::string>> parseHtml(const std::string& htmlContent);
};

#endif // HTMLPARSER_H