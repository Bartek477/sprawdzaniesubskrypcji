#include <pybind11/pybind11.h>
#include <pybind11/embed.h> // Use pybind11 to embed Python
#include <iostream>
#include <string>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // Start the Python interpreter

    auto parse_html = py::module_::import("parse_html").attr("parse_html");
    std::string html_content = "<html><body><a href='http://example.com'>Example</a></body></html>";
    auto links = parse_html(html_content).cast<py::list>();
    
    for (const auto& link : links) {
        std::cout << "Found link: " << link.cast<std::string>() << std::endl;
    }

    return 0;
}