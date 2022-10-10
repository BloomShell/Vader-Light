#pragma once
#include <type_traits>


template<typename T, typename ... Types>
struct is_any : std::bool_constant<(
    std::is_same_v<T, Types> || ...)> {};