#include <iostream>
#include "Bibliotheque.h"
#include "Livre.h"
#include "Adherent.h"
using namespace std;

Bibliotheque::Bibliotheque() : nom(""), adresse(""), code(0), listeLivres(nullptr), listeAdherents(nullptr), capaciteMax(100), nombreLivres(0) {}

Bibliotheque::Bibliotheque(string nom, string adresse, int code, int capaciteMax)
    : nom(nom), adresse(adresse), code(code), listeLivres(nullptr), listeAdherents(nullptr), capaciteMax(capaciteMax), nombreLivres(0) {}

void Bibliotheque::ajouterLivre(Livre* livre) {
    livre->suivant = listeLivres;
    listeLivres = livre;
    nombreLivres++;
}

void Bibliotheque::afficherLivres() {
    Livre* livre = listeLivres;
    while (livre != nullptr) {
        livre->afficher_details();
        livre = livre->suivant;
    }
}

void Bibliotheque::acheterLivre(Livre* livre) {
    if (nombreLivres >= capaciteMax){
        throw overflow_error("la bibliothèque à déjà atteint ça capacité maximale");
        return;
    }
    ajouterLivre(livre);
}

void Bibliotheque::supprimerLivre(int codeLivre) {
    Livre* livre = listeLivres;
    Livre* precedent = nullptr;
    while (livre != nullptr) {
        if (livre->getcode() == codeLivre) {
            if (precedent == nullptr) {
                listeLivres = livre->suivant;
            } 
            else {
                precedent->suivant = livre->suivant;
            }
            delete livre;
            nombreLivres--;
            return;
        }
        precedent = livre;
        livre = livre->suivant;
    }
    throw runtime_error("Livre non trouvé dans la bibliothèque.");
}

void Bibliotheque::ajouterAdherent(Adherent* adherent) {
    adherent->suivant = listeAdherents;
    listeAdherents = adherent;
}

void Bibliotheque::supprimerAdherent(int numeroAdherent) {
    Adherent* adherent = listeAdherents;
    Adherent* precedent = nullptr;
    while (adherent != nullptr) {
        if (adherent->getnumero() == numeroAdherent) {
            if (precedent == nullptr) {
                listeAdherents = adherent->suivant;
            }
            else {
                precedent->suivant = adherent->suivant;
            }
            delete adherent;
            return;
        }
        precedent = adherent;
        adherent = adherent->suivant;
    }
    throw runtime_error("Adhérent non trouvé dans la bibliothèque.");
}

void Bibliotheque::emprunterLivre(int codeLivre, int numeroAdherent) {
    Adherent* adherent = listeAdherents;
    while (adherent != nullptr) {
        if (adherent->getnumero() == numeroAdherent) {
            if (adherent->getlivresempruntes().size() >= adherent->maxLivres){
                throw overflow_error("l'adhérent à déjà atteint son maximum de livres");
                return;
            }
            adherent->emprunter(codeLivre);
            return;
        }
        adherent = adherent->suivant;
    }
    throw runtime_error("Adhérent non trouvé dans la bibliothèque.");
}

void Bibliotheque::rendreLivre(int codeLivre, int numeroAdherent) {
    Adherent* adherent = listeAdherents;
    while (adherent != nullptr) {
        if (adherent->getnumero() == numeroAdherent) {
            adherent->retourner(codeLivre);
            return;
        }
        adherent = adherent->suivant;
    }
    throw runtime_error("Adhérent non trouvé dans la bibliothèque.");
}

void Bibliotheque::demanderLivreAutreBibliotheque(string isbn, Bibliotheque bibliothequeDest) {
    if (nombreLivres >= capaciteMax){
        throw overflow_error("la bibliothèque à déjà atteint ça capacité maximale");
    }
    Livre* livre = bibliothequeDest.listeLivres;
    while (livre != nullptr) {
        if (livre->getisbn() == isbn) {
            ajouterLivre(livre);
            bibliothequeDest.supprimerLivre(livre->getcode());
            return;
        }
        livre = livre->suivant;
    }
    throw runtime_error("Livre non trouvé dans la bibliothèque.");
}

void Bibliotheque::rendreLivresPretes() {
    Livre* livre = listeLivres;
    Livre* precedent = nullptr;
    while (livre != nullptr){
        if (livre->bibliothequeOrigine.getNom() == nom and livre->etat == "libre"){
            if (precedent == nullptr) {
                listeLivres = livre->suivant;
            } 
            else {
                precedent->suivant = livre->suivant;
            }
            livre->bibliothequeOrigine.ajouterLivre(livre);
        }
        precedent = livre;
        livre = livre->suivant;
    }
}

string Bibliotheque::getNom() {
    return nom;
}

string Bibliotheque::getAdresse() {
    return adresse;
}

int Bibliotheque::getCode() {
    return code;
}

Livre* Bibliotheque::getListeLivres() {
    return listeLivres;
}

Adherent* Bibliotheque::getListeAdherents() {
    return listeAdherents;
}

int Bibliotheque::getCapaciteMax() {
    return capaciteMax;
}

int Bibliotheque::getNombreLivres() {
    return nombreLivres;
}

void Bibliotheque::setNom(string nom) {
    this->nom = nom;
}

void Bibliotheque::setAdresse(string adresse) {
    this->adresse = adresse;
}

void Bibliotheque::setCode(int code) {
    this->code = code;
}

void Bibliotheque::setCapaciteMax(int capaciteMax) {
    this->capaciteMax = capaciteMax;
}

void Bibliotheque::setNombreLivres(int nombreLivres) {
    this->nombreLivres = nombreLivres;
}
