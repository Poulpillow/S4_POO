#include "hangman.hpp"
#include <string>
#include <vector>
#include "random.hpp"

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

void play_hangman()
{
    /*
        - Phrases de début (Bienvenue + Règles + Nombres de vies)
        - Créer une liste de mots
        - Choisir un mot dans cette liste
        - Créer le mot caché (avec le bon nombre de tirets)
        - Boucle :
            - Afficher le mot caché
            - Afficher le nombre de vies
            - Demander une lettre
            - Récup de la lettre
            - Tester la lettre
            - Modifier le mot caché OU enlever de la vie
            - Continuer tant que le mot caché contient des tirets OU qu'il reste de la vie
        - Message de fin (gagné ou perdu)
    */

    // Phrases de début (Bienvenue + Règles + Nombres de vies)
    std::cout << "Welcome to Hangman !\nThe rules are simple : you have 10 lives to guess the secret word\nLet's get started !\n";

    //  Créer une liste de mots + Choisir un mot dans cette liste
    std::string unknown_word = random_word();

    // Créer le mot caché (avec le bon nombre de tirets)
    // Créer un tableau de la longueur du mot inconnu
    // Le remplir de tirets
    // Faire en sorte que l'on peut modifier dynamiquement le mot inconnu + que l'on puisse accéder à chaque élément du tableau
    std::vector<char> hidden_word = {};
    for (int i = 0; i < unknown_word.size(); i++) {
        hidden_word.push_back('_');
    }
}
