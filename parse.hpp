#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

using namespace std::filesystem;

namespace cmd {
    void init() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
    }

    auto readlines(std::ifstream& infile) -> std::vector<std::string> {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(infile, line)) lines.push_back(std::move(line));
        return lines;
    }

    auto split(const std::string& s) -> std::vector<std::string> {
        std::vector<std::string> tokens;
        std::istringstream iss{s};
        std::string token;

        while (iss >> token) {
            tokens.push_back(std::move(token));
        }
        return tokens;
    }

    auto split(const std::string& s, const std::string& d) -> std::vector<std::string> {
        std::vector<std::string> tokens;
        std::string::size_type start = 0;
        auto end = s.find(d, start);

        while (end != std::string::npos) {
            tokens.push_back(std::move(s.substr(start, end - start)));
            start = end + d.length();
            end = s.find(d, start);
        }
        tokens.push_back(s.substr(start, end - start));
        return tokens;
    }
};
