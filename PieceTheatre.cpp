#include <iostream>
#include "PieceTheatre.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
PieceTheatre::PieceTheatre(string auteur, string titre, string editeur, string isbn, string siecle)
    : Livre(auteur, titre, editeur, isbn), siecle(siecle) {}

// Constructeur de recopie
PieceTheatre::PieceTheatre(Livre livre, string siecle)
    : Livre(livre), siecle(siecle) {}

// Getter pour formatPoeme
string PieceTheatre::getsiecle() {
    return siecle;
}

// Setter pour formatPoeme
void PieceTheatre::setsiecle(string nouveausiecle) {
    siecle = nouveausiecle;
}

// Destructeur
PieceTheatre::~PieceTheatre() {
    // Nettoyage si nécessaire
}
