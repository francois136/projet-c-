#include <iostream>
#include "adherent.h"
#include <string>
using namespace std;

Adherent::Adherent(string n,string p,string a,int n,Bibliotheque b,int m){
    nom = n;
    prenom = p;
    adresse = a;
    numero = n;
    bibliotheque = b;
    maxLivres = m;
    Livresempruntes = {};
    suivant = nullptr;
}

Adherent::Adherent(Bibliotheque b){
    nom = "";
    prenom = "";
    adresse = "";
    numero = 0;
    bibliotheque = b;
    Livresempruntes = {};
    suivant = nullptr;
}

void Adherent::emprunter(Livre livre) {
    if (livresEmpruntes.size() < maxLivres) {
        livresEmpruntes.push_back(livre);
    } else {
        throw runtime_error("Nombre maximum de livres empruntés atteint.");
    }
}

void Adherent::retourner(Livre) {
    livresEmpruntes.remove(livre);
}

string Adherent::gentom(){
    return nom;
}

string Adherent::getprenom(){
    return prenom;
}

string Adherent::getadress(){
    return adresse;
}

int Adherent::getnumero(){
    return numero;
}

Bibliotheque Adherent::getbibliotheque(){
    return bibliotheque;
}

list<Livre> Adherent::getlivresempruntes(){
    return livresempruntes;
}

int Adherent::getmaxLivres(){
    return maxlivres;
}

void Adherent::sentnom(string n){
    nom = n
}

void Adherent::setprenom(string p){
    prenom = p;
}

void Adherent::setadresse(string a){
    adresse = a;
}

void Adherent::setnumero(int n){
    numero = n;
}

void Adherent::setbibliotheque(Biblioteque b){
    bibliotheque = b;
}

void Adherent::setlivresempruntes(list<Livre> l){
    Livresempruntes = l;
}

void Adherent::setmaxLivres(int m){
    maxLivres = m;
}
