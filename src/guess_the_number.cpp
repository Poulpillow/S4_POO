#include "guess_the_number.hpp"
#include <iostream>
#include "random.hpp"

void play_guess_the_number()
{
    const int unknown_number = random_object(1, 100);
    int       round          = 1;

    std::cout << "\nWelcome to Guess the number !\nPick a number between 1 and 100\n";
    int picked_number;
    std::cin >> picked_number;

    while (picked_number != unknown_number) {
        if (picked_number > unknown_number) {
            std::cout << "Smaller\n\n/----------------------------------------------------/\n";
        }
        else {
            std::cout << "Greater\n\n/----------------------------------------------------/\n";
        }
        std::cout << "\nTry again\n";
        std::cin >> picked_number;
        round++;
    }
    std::cout << "\nCongrats, you won in " << round << " rounds !\n\n";
}
