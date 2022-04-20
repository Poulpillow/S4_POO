#include "hangman.hpp"
#include <string>
#include <vector>
#include "random.hpp"

std::string random_word()
{
    const std::vector<std::string> word_list = {
        "imac",
        "animaux",
        "pays",
        "bonsoir",
        "cochon"};
    const int         index = random_number(0, static_cast<int>(word_list.size()) - 1);
    const std::string word  = word_list[index];
    return word;
}

void play_hangman()
{
    // Phrases de début (Bienvenue + Règles + Nombres de vies)
    std::cout << "Welcome to Hangman !\nThe rules are simple : you have 10 lives to guess the secret word\nLet's get started !\n";

    //  Créer une liste de mots + Choisir un mot dans cette liste

    const std::string unknown_word       = random_word();
    const size_t      lengh_unknown_word = unknown_word.size();

    // Créer le mot caché (avec le bon nombre de tirets)
    // Créer un tableau de la longueur du mot inconnu
    // Le remplir de tirets
    // Faire en sorte que l'on peut modifier dynamiquement le mot inconnu + que l'on puisse accéder à chaque élément du tableau

    std::vector<char> hidden_word = {};
    for (size_t i = 0; i < lengh_unknown_word; i++) {
        hidden_word.push_back('_');
    }

    // Boucle :
    // - Afficher le mot caché
    // - Afficher le nombre de vies
    // - Demander une lettre
    // - Récup de la lettre
    // - Tester la lettre
    // - Modifier le mot caché OU enlever de la vie
    // - Continuer tant que le mot caché contient des tirets OU qu'il reste de la vie

    int  number_lives        = 10;
    bool hidden_word_founded = false;
    char picked_letter       = ' ';

    while (number_lives != 0 && !hidden_word_founded) {
        int         position = -2;
        std::string show_hidden_word(hidden_word.begin(), hidden_word.end());
        std::cout << "Here is the current hidden word :\n"
                  << show_hidden_word << "\nYou have " << number_lives << " lives\nChoose a letter\n";
        std::cin >> picked_letter;

        position = unknown_word.find(picked_letter);

        if (position != -1) {
            for (size_t i = 0; i < lengh_unknown_word; i++) {
                if (unknown_word.at(i) == picked_letter) {
                    hidden_word[i] = picked_letter;
                }
            }

            // A AMELIORER
            hidden_word_founded = true;
            for (size_t i = 0; i < lengh_unknown_word; i++) {
                if (hidden_word[i] == '_') {
                    hidden_word_founded = false;
                }
            }
        }
        else {
            number_lives--;
        }
    }

    // Message de fin (gagné ou perdu)

    if (hidden_word_founded) {
        std::cout << "Congrats ! You found the word ! It was " << unknown_word << "\n\n";
    }
    else if (number_lives == 0) {
        std::cout << "Oh no ! You lost all you lives ... Sorry bro\nThe word was " << unknown_word << "\n\n";
    }
    else {
        std::cout << "ERROR : THAT CAN NEVER HAPPEND !!!\n\n";
    }
}
