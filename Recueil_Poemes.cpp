#include <iostream>
#include "Recueil_Poemes.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
RecueilPoemes::RecueilPoemes(string auteur, string titre, string editeur, string isbn, string formatPoeme)
    : Livre(auteur, titre, editeur, isbn), formatPoeme(formatPoeme) {}

// Constructeur de recopie
RecueilPoemes::RecueilPoemes(Livre livre, string formatPoeme)
    : Livre(livre), formatPoeme(formatPoeme) {}

// Getter pour formatPoeme
string RecueilPoemes::getFormatPoeme() {
    return formatPoeme;
}

// Setter pour formatPoeme
void RecueilPoemes::setFormatPoeme(string nouveauFormatPoeme) {
    formatPoeme = nouveauFormatPoeme;
}

// Destructeur
RecueilPoemes::~RecueilPoemes() {
    // Nettoyage si nécessaire
}
