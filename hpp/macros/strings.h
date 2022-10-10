#pragma once
#include "..\utils\types.h"
#include <array>
#include <string>
#include <boost/algorithm/string.hpp>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <regex>


template<typename T>
std::unordered_set<int> nonzero(
    const std::vector<T>& v
) {
    static_assert(is_any<T, float, double, int>::value,
        "Must be vector of doubles, floats or ints.");
    std::unordered_set<int> indexes;
    for (int i = 0; i < v.size(); i++)
        if (v[i] != 0) indexes.insert(i);
    return indexes;
};


void scrubstr(
    std::string& input,
    bool tolower = true
);


std::vector<std::string> tokenize(
    const std::string& input
);