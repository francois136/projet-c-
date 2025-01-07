#include "Livre.h"
#include <iostream>
using namespace std;

void Livre::changer_etat(nouvel_etat){
    etat = nouvel_etat;
}

void Livre::afficher_details(){
    cout << "code : " << code << endl;
    cout << "auteur : " << auteur << endl;
    cout << "titre : " << titre << endl;
    cout << "editeur : " << editeur << endl;
    cout << "numéro isbn : " << isbn << endl;
    cout << "public : " << publics << endl;
    cout << "état : " << etat << endl;
    cout << "bibliothèque" << bibliotheque << endl;
}

int Livre::getcode(){
    return code;
}
string Livre::getauteur(){
    return code;
}

string Livre::gettitre(){
    return titre;
}

string Livre::getediteur(){
    return editeur;
}

string Livre::getisbn(){
    return isbn;
}

string Livre::getpublics(){
    return publics;
}

string Livre::getetat(){
    return etat;
}

Bibliotheque Livre::getbibliotheque(){
    return bibliotheque;
}

void Livre::setetat(nouveletat){
    etat = nouveletat;
}
