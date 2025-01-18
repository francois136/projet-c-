#include <iostream>
#include "BandeDessinee.h"
#include "template.cpp"
#include "Bibliotheque.h"
using namespace std;

BandeDessinee::BandeDessinee(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string dessinateur)
    : Livre(code, auteur, titre, editeur, isbn, publics, etat, bibliothequeOrigine), 
    dessinateur(dessinateur) {}

BandeDessinee::BandeDessinee(Livre& livre, string dessinateur)
    : Livre(livre), dessinateur(dessinateur) {}

string BandeDessinee::getDessinateur(){
    return dessinateur;
}

void BandeDessinee::setDessinateur(string nouveauDessinateur){
    dessinateur = nouveauDessinateur;
}

void BandeDessinee::afficher_details(){ 
    afficher_details_template(*this); 
    cout << "Dessinateur: " << dessinateur << endl;
}

BandeDessinee::~BandeDessinee() {}
