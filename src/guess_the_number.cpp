#include "guess_the_number.hpp"
#include <iostream>
#include "random.hpp"

void play_guess_the_number()
{
    const int unknown_number = random_object(1, 100); // The function pick a number between 1 and 100
    int       round          = 1;

    // First round
    std::cout << "\nWelcome to Guess the Number !\nRules are simple ! I pick a number between 1 and 100 and you have to guess it !\nPretty simple isn 't it ? Let' s start !\nPick a number between 1 and 100\n";
    int picked_number;
    std::cin >> picked_number;

    // Game Loop
    while (picked_number != unknown_number) {
        if (picked_number > unknown_number) {
            std::cout << "It's smaller\n\n/----------------------------------------------------/\n";
        }
        else {
            std::cout << "It's greater\n\n/----------------------------------------------------/\n";
        }
        std::cout << "\nLet's try again ! Pick a number between 1 and 100\n";
        std::cin >> picked_number;
        round++;
    }
    std::cout << "\nCongratulations human, you won in " << round << " rounds !\n\n";
}
