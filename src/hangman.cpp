#include "hangman.hpp"

std::string random_word()
{
    std::vector<std::string> word_list = {
        "Chat",
        "Chien",
        "Cheval",
        "Souris",
        "Cochon"};
    int         index = random_number(0, static_cast<int>(word_list.size()) - 1);
    std::string word  = word_list[index];
    return word;
}
