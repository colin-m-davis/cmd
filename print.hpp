#include <iostream>
#include <string>
#include <utility>
#include <iterator>

namespace cmd {
    void printd_arg(const auto& delim, bool is_first, const auto& arg) {
        if (!is_first) std::cout << delim;
        std::cout << arg;
    }

    template <std::size_t... I>
    void printd_helper(const auto& delim, auto&& tup, std::index_sequence<I...>) {
        (printd_arg(delim, I == 0, std::get<I>(tup)), ...);
    }

    void printd(const auto& delim, auto&&... args) {
        printd_helper(
            delim,
            std::forward_as_tuple(args...),
            std::make_index_sequence<sizeof...(args)>());
        std::cout << '\n';
    }

    void print(auto&&... args) {
        printd(' ', args...);
    }

    template <typename It>
    void printr(It begin, It end, const std::string& delim = " ") {
        std::cout << *begin;
        for (auto it = std::next(begin); it != end; ++it) {
            std::cout << delim << *it;
        }
        std::cout << '\n';
    }
    
    void printl(const auto& l, const std::string& delim = " ") {
        std::cout << *std::begin(l);
        for (auto it = std::next(std::cbegin(l)); it != std::cend(l); ++it) {
            std::cout << delim << *it;
        }
        std::cout << '\n';
    }

    void printg(const auto& g, const std::string& delim = " ") {
        for (const auto& row : g) {
            printl(row, delim);
        }
    }

    void sep() {
        std::cout << "~~~~\n";
    }
};
