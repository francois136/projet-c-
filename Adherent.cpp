#include <iostream>
#include "Adherent.h"
#include "Bibliotheque.h"
#include "Livre.h"
#include <string>

using namespace std;

Adherent::Adherent(string n, string p, string a, int num, Bibliotheque b, int m) {
    nom = n;
    prenom = p;
    adresse = a;
    numero = num;
    bibliotheque = b;
    maxLivres = m;
    Livresempruntes = {};
    suivant = nullptr;
}

Adherent::Adherent(Bibliotheque b) {
    nom = "";
    prenom = "";
    adresse = "";
    numero = 0;
    bibliotheque = b;
    Livresempruntes = {};
    suivant = nullptr;
}

void Adherent::emprunter(int codeLivre) {
    Livre* livre = bibliotheque.getListeLivres(); 
    while (livre != nullptr) {
        if (livre->getcode() == codeLivre) {
            if (Livresempruntes.size() < maxLivres) {
                livre->changer_etat("Emprunté");
                Livresempruntes.push_back(*livre);
                return;
            } else {
                throw runtime_error("Nombre maximum de livres empruntés atteint.");
            }
        }
        livre = livre->suivant;
    }
    throw runtime_error("Livre non trouvé dans la bibliothèque.");
}

void Adherent::retourner(int codeLivre) {
    for (auto it = Livresempruntes.begin(); it != Livresempruntes.end(); ++it) {
        if (it->getcode() == codeLivre) {
            it->changer_etat("Disponible");
            Livresempruntes.erase(it);
            return;
        }
    }
    throw runtime_error("Livre non trouvé dans la liste des livres empruntés.");
}

string Adherent::gentom() {
    return nom;
}

string Adherent::getprenom() {
    return prenom;
}

string Adherent::getadress() {
    return adresse;
}

int Adherent::getnumero() {
    return numero;
}

Bibliotheque Adherent::getbibliotheque() {
    return bibliotheque;
}

list<Livre> Adherent::getlivresempruntes() {
    return Livresempruntes;
}

int Adherent::getmaxLivres() {
    return maxLivres;
}

void Adherent::sentnom(string n) {
    nom = n;
}

void Adherent::setprenom(string p) {
    prenom = p;
}

void Adherent::setadresse(string a) {
    adresse = a;
}

void Adherent::setnumero(int n) {
    numero = n;
}

void Adherent::setbibliotheque(Bibliotheque b) {
    bibliotheque = b;
}

void Adherent::setlivresempruntes(list<Livre> l) {
    Livresempruntes = l;
}

void Adherent::setmaxLivres(int m) {
    maxLivres = m;
}
