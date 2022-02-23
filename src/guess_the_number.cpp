#include "guess_the_number.hpp"

int pick_random_number()
{
    std::random_device                 rd;
    std::mt19937                       mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    return dist(mt);
}

void guess_the_number()
{
    int n = pick_random_number();
    int i;
    int index = 1;
    std::cout << "Pick a number between 1 and 100\n";
    std::cin >> i;
    while (i != n) {
        if (i > n) {
            std::cout << "Smaller\n";
        }
        else {
            std::cout << "Greater\n";
        }
        std::cout << "Try again\n";
        std::cin >> i;
        index++;
    }
    std::cout << "Congrats, you won in " << index << " rounds !\n";
}
