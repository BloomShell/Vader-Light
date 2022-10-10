#pragma once
#include "..\utils\types.h"
#include <array>
#include <string>
#include <boost/algorithm/string.hpp>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <regex>


void scrubstr(
    std::string& input,
    bool tolower = true
);


std::vector<std::string> tokenize(
    const std::string& input
);