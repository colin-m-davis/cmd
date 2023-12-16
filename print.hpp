#include <iostream>
#include <string>
#include <utility>

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
};
