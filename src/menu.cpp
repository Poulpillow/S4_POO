#include "menu.hpp"
#include <iostream>
#include "guess_the_number.hpp"
#include "hangman.hpp"
#include "noughts_and_crosses.hpp"

void choose_game()
{
    char index      = '\0';
    bool isQuitting = false;

    while (!isQuitting) {
        std::cout << R"(
Welcome to the menu ! Choose a game :
1 --> Guess the number
2 --> Hangman
3 --> Noughts and Crosses
q --> Quit the menu
)";
        std::cin >> index;
        // -------------------------------- GUESS THE NUMBER --------------------------------- //
        if (index == '1') {
            play_guess_the_number();
        }

        // ------------------------------------ HANGMAN -------------------------------------- //
        else if (index == '2') {
            play_hangman();
        }

        // ------------------------------ NOUGHTS AND CROSSES -------------------------------- //
        else if (index == '3') {
            play_noughts_and_crosses();
        }

        // ------------------------------------- QUIT ---------------------------------------- //
        else if (index == 'q') {
            std::cout << "See you soon !\n";
            isQuitting = true;
        }

        // ------------------------------------- ERROR --------------------------------------- //
        else {
            std::cout << "This is not a valid command. Try again.\n";
        }
    }
}