#include <iostream>
#include "Album.h"
#include "template.cpp"
#include "Bibliotheque.h"
using namespace std;

Album::Album(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string illustration)
    : Livre(code, auteur, titre, editeur, isbn, publics, etat, bibliothequeOrigine), illustration(illustration) {}

Album::Album(Livre& livre, string illustration)
    : Livre(livre), illustration(illustration) {}

string Album::getillustration() {
    return illustration;
}

void Album::setsillustration(string nouvelleIllustration) {
    illustration = nouvelleIllustration;
}

void Album::afficher_details() {
    afficher_details_template(*this);
    cout << "Illustration: " << illustration << endl;
}

Album::~Album() {}
