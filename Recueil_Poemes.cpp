#include <iostream>
#include "Recueil_Poemes.h"
#include "template.cpp"
#include "Bibliotheque.h"
using namespace std;

Recueil_Poemes::Recueil_Poemes(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string formatPoeme)
    :Livre(code, auteur, titre, editeur, isbn, publics, etat, bibliothequeOrigine), 
    formatPoeme(formatPoeme) {}

Recueil_Poemes::Recueil_Poemes(Livre& livre, string formatPoeme)
    : Livre(livre), 
    formatPoeme(formatPoeme) {}

string Recueil_Poemes::getformatPoeme() {
    return formatPoeme;
}

void Recueil_Poemes::setformatPoeme(string nouveauFormatPoeme) {
    formatPoeme = nouveauFormatPoeme;
}

void Recueil_Poemes::afficher_details() {
    afficher_details_template(*this);
    cout << "Format du Poème: " << formatPoeme << endl;
}

Recueil_Poemes::~Recueil_Poemes() {}
