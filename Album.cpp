#include <iostream>
#include "Album.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
Album::Album(string auteur, string titre, string editeur, string isbn, string illustration)
    : Livre(auteur, titre, editeur, isbn), illustration(illustration) {}

// Constructeur de recopie
Album::Album(Livre livre, string illustration)
    : Livre(livre), illustration(illustration) {}

// Getter pour formatPoeme
string Album::getillustration() {
    return illustration;
}

// Setter pour formatPoeme
void Album::setillustration(string nouveauillustration) {
    illustration = nouveauillustration;
}

// Destructeur
Album::~Album() {
    // Nettoyage si nécessaire
}
