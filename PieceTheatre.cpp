#include <iostream>
#include "PieceTheatre.h"
#include "Template.cpp"
#include "Bibliotheque.h"
using namespace std;

PieceTheatre::PieceTheatre(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string siecle)
    :Livre(code, auteur, titre, editeur, isbn, publics, etat, bibliothequeOrigine), 
    siecle(siecle) {}

PieceTheatre::PieceTheatre(Livre& livre, string siecle)
    : Livre(livre), siecle(siecle) {}

string PieceTheatre::getsiecle() {
    return siecle;
}

void PieceTheatre::setsiecle(string nouveauSiecle) {
    siecle = nouveauSiecle;
}

void PieceTheatre::afficher_details() {
    afficher_details_template(*this);
    cout << "Siècle: " << siecle << endl;
}

PieceTheatre::~PieceTheatre() {}
