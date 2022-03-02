#include "guess_the_number.hpp"

void play_guess_the_number()
{
    const int unknown_number = random_number(1, 100);
    int       picked_number;
    int       round = 1;

    std::cout << "Welcome to Guess the number !\nPick a number between 1 and 100\n";
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
