#include <iostream>
#include "Recueil_Poemes.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
Recueil_Poemes::Recueil_Poemes(string auteur, string titre, string editeur, string isbn, string formatPoeme)
    : Livre(auteur, titre, editeur, isbn), formatPoeme(formatPoeme) {}

// Constructeur de recopie
Recueil_Poemes::Recueil_Poemes(Livre livre, string formatPoeme)
    : Livre(livre), formatPoeme(formatPoeme) {}

// Getter pour formatPoeme
string Recueil_Poemes::getFormatPoeme() {
    return formatPoeme;
}

// Setter pour formatPoeme
void Recueil_Poemes::setFormatPoeme(string nouveauFormatPoeme) {
    formatPoeme = nouveauFormatPoeme;
}

// Destructeur
Recueil_Poemes::~Recueil_Poemes() {
    // Nettoyage si nécessaire
}
