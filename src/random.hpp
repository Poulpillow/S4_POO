#pragma once
#include <random>

template<typename T>
T random_object(const T& min, const T& max)
{
    static std::random_device        rd;
    static std::mt19937              mt(rd());
    std::uniform_int_distribution<T> dist(min, max);
    return dist(mt);
}