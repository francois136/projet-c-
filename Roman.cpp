#include <iostream>
#include "Roman.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
Roman::Roman(string auteur, string titre, string editeur, string isbn, string genre)
    : Livre(auteur, titre, editeur, isbn), genre(genre) {}

// Constructeur de recopie
Roman::Roman(Livre livre, string genre)
    : Livre(livre), genre(genre) {}

// Getter pour formatPoeme
string Roman::getgenre() {
    return genre;
}

// Setter pour formatPoeme
void Roman::setgenre(string nouveaugenre) {
    genre = nouveaugenre;
}

// Destructeur
Roman::~Roman() {
    // Nettoyage si nécessaire
}
