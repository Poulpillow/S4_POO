#include "hangman.hpp"
#include <string>
#include <vector>
#include "random.hpp"

std::string random_word()
{
    const std::vector<std::string> word_list = {
        "imac",
        "baguette",
        "code",
        "jules",
        "talin",
        "crepe",
        "vacances"};
    const int         index = random_object(0, static_cast<int>(word_list.size()) - 1);
    const std::string word  = word_list[index];
    return word;
}

void play_hangman()
{
    //-----------------------------------------------//
    //------------ Beginning of the Game ------------//
    //-----------------------------------------------//

    std::cout << "\nWelcome to Hangman !\nRules are simple : you have 10 lives to guess the secret word !\nLet's get started !\n";

    //  Choose a random word in the list of the function random_word() + keep the lengh of the word
    const std::string unknown_word       = random_word();
    const size_t      lengh_unknown_word = unknown_word.size();

    // Creating the hidden word
    std::vector<char> hidden_word = {};
    for (size_t i = 0; i < lengh_unknown_word; i++) {
        hidden_word.push_back('_');
    }

    // Set the variables
    int  number_lives        = 10;
    bool hidden_word_founded = false;
    char picked_letter       = ' ';

    //-----------------------------------------------//
    //-------------------- Loop ---------------------//
    //-----------------------------------------------//

    while (number_lives != 0 && !hidden_word_founded) {
        // Draw the text of the actual round
        std::string show_hidden_word(hidden_word.begin(), hidden_word.end());
        std::cout << "\n/----------------------------------------------------/\n\nHere is the current hidden word : "
                  << show_hidden_word << "\nYou have " << number_lives << " lives\n\nChoose a letter\n";
        std::cin >> picked_letter;

        // Is there the letter if the word ?
        size_t position = unknown_word.find(picked_letter);
        // Yes
        if (position != std::string::npos) {
            // Change of the guessed letters
            for (size_t i = 0; i < lengh_unknown_word; i++) {
                if (unknown_word.at(i) == picked_letter) {
                    hidden_word[i] = picked_letter;
                }
            }

            // If the hidden is complete : stop the loop
            hidden_word_founded = true;
            for (size_t i = 0; i < lengh_unknown_word; i++) {
                if (hidden_word[i] == '_') {
                    hidden_word_founded = false;
                }
            }
        }
        // No
        else {
            number_lives--;
        }
    }

    //-----------------------------------------------//
    //--------------- End of the Game ---------------//
    //-----------------------------------------------//

    // You won
    if (hidden_word_founded) {
        std::cout << "\nCongrats ! You found the word ! It was " << unknown_word << "\n\n";
    }

    // You lost
    else if (number_lives == 0) {
        std::cout << "\nOh no ! You lost all you lives ... Sorry bro\nThe word was " << unknown_word << "\n\n";
    }

    // Error
    else {
        std::cout << "\nERROR : THAT CAN NEVER HAPPEND !!!\n\n";
    }
}
