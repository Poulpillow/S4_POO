#include "guess_the_number.hpp"

int random_number()
{
    std::random_device                 rd;
    std::mt19937                       mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    return dist(mt);
}

void play_guess_the_number()
{
    int unknown_number = random_number();
    int picked_number;
    int round = 1;

    std::cout << "Welcome to Guess the number !\n Pick a number between 1 and 100\n";
    std::cin >> picked_number;

    while (picked_number != unknown_number) {
        if (picked_number > unknown_number) {
            std::cout << "Smaller\n";
        }
        else {
            std::cout << "Greater\n";
        }
        std::cout << "Try again\n";
        std::cin >> picked_number;
        round++;
    }
    std::cout << "Congrats, you won in " << round << " rounds !\n";
}
