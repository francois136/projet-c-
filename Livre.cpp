#include <iostream>
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

Livre::Livre(int c, string a, string t, string e, string i, string p, string et, Bibliotheque b){
    code = c;
    auteur = a;
    titre = t;
    editeur = e;
    isbn = i;
    publics = p;
    etat = et;
    bibliothequeOrigine = b;
    suivant = nullptr;
}

Livre::Livre(Bibliotheque b){
    code = 0;
    auteur = "";
    titre = "";
    editeur = "";
    isbn = "";
    publics = "";
    etat = "";
    bibliothequeOrigine = b;
    suivant = nullptr;
}

void Livre::changer_etat(string nouvel_etat) {
    etat = nouvel_etat;
}

int Livre::getcode() {
    return code;
}

string Livre::getauteur() {
    return auteur;
}

string Livre::gettitre() {
    return titre;
}

string Livre::getediteur() {
    return editeur;
}

string Livre::getisbn() {
    return isbn;
}

string Livre::getpublics() {
    return publics;
}

string Livre::getetat() {
    return etat;
}

Bibliotheque Livre::getbibliotheque() {
    return bibliothequeOrigine;
}

void Livre::setcode(int c) {
    code = c;
}

void Livre::setauteur(string a) {
    auteur = a;
}

void Livre::settitre(string t) {
    titre = t;
}

void Livre::setediteur(string e) {
    editeur = e;
}

void Livre::setisbn(string i) {
    isbn = i;
}

void Livre::setpublics(string p) {
    publics = p;
}

void Livre::setetat(string et) {
    etat = et;
}

void Livre::setbibliotheque(Bibliotheque b) {
    bibliothequeOrigine = b;
}