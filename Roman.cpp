#include <iostream>
#include "Roman.h"
#include "template.cpp"
#include "Bibliotheque.h"
using namespace std;

Roman::Roman(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string genre)
    :Livre(code, auteur, titre, editeur, isbn, publics, etat, bibliothequeOrigine),
    genre(genre) {}

Roman::Roman(Livre& livre, string genre)
    : Livre(livre), 
    genre(genre) {}

string Roman::getgenre() {
    return genre;
}

void Roman::setgenre(string nouveauGenre) {
    genre = nouveauGenre;
}

void Roman::afficher_details() {
    afficher_details_template(*this);
    cout << "Genre: " << genre << endl;
}

Roman::~Roman() {}
