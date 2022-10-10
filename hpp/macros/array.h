#pragma once
#include "..\utils\types.h"
#include <unordered_set>


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