#include "Livre.h"
#include <iostream>
using namespace std;

void Livre::changer_etat(nouvel_etat){
    etat = nouvel_etat;
}

Livre::Livre(){
    code = 0;
    auteur = "";
    titre = "";
    editeur = "";
    isbn = "";
    publics = "";
    etat = "";
    bibliothequeOrigine = null;
}
Livre::Livfre(int c,string a,string t,string ed,string i,string p,string e ,Bibliotheque b){
    code = c;
    auteur = a;
    titre = t;
    editeur = ed;
    isbn = i;
    publics = p;
    etat = e;
    bibliothequeOrigine = b;
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
