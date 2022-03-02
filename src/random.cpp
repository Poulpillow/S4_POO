#include "random.hpp"

// A template here will be nice
int random_number(int min, int max)
{
    static std::random_device          rd;
    static std::mt19937                mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}