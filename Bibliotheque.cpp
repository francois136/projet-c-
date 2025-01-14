#include "Bibliotheque.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

Bibliotheque::Bibliotheque(){
    nom = "";
    adresse = "";
    code = 0;
    listeLivres = nullptr;
    listeAdherent = nullptr;
    capaciteMax = 100;
    nombreLivres = 0
}

Bibliotheque::Bibliotheque(string n, string adresse, int code, int capaciteMax)
    nom = n;
    adresse = a;
    code = c;
    capaciteMax = m;
    nombreLivres = 0;
    listeLivres = nullptr;
    listeAdherent = nullptr;
}

// Ajouter un livre à la bibliothèque
void Bibliotheque::ajouterLivre(const Livre& livre) {
    if (nombreLivres >= capaciteMax) {
        cout << "Erreur : La capacité maximale de la bibliothèque est atteinte." << endl;
        return;
    }

    Livre* nouveauLivre = new Livre(livre); // Copie du livre
    nouveauLivre->suivant = listeLivres;
    listeLivres = nouveauLivre;
    nombreLivres++;
}

// Afficher les livres disponibles
void Bibliotheque::afficherLivres() const {
    if (!listeLivres) {
        cout << "La bibliothèque ne contient aucun livre." << endl;
        return;
    }

    Livre* livre = listeLivres;
    while (courant) {
        livre->afficher_details();
        livre = livre->suivant;
    }
}

// Supprimer un livre par son code
void Bibliotheque::supprimerLivre(int codeLivre) {
    Livre** courant = &listeLivres;
    while (*courant) {
        if ((*courant)->getcode() == codeLivre) {
            Livre* aSupprimer = *courant;
            *courant = (*courant)->suivant;
            delete aSupprimer;
            nombreLivres--;
            return;
        }
        courant = &((*courant)->suivant);
    }
    cout << "Erreur : Livre avec le code " << codeLivre << " non trouvé." << endl;
}

// Ajouter un adhérent
void Bibliotheque::ajouterAdherent(const Adherent& adherent) {
    Adherent* nouvelAdherent = new Adherent(adherent);
    nouvelAdherent->suivant = listeAdherents;
    listeAdherents = nouvelAdherent;
}

// Supprimer un adhérent par son numéro
void Bibliotheque::supprimerAdherent(int numeroAdherent) {
    Adherent** courant = &listeAdherents;
    while (*courant) {
        if ((*courant)->getnumero() == numeroAdherent) {
            Adherent* aSupprimer = *courant;
            *courant = (*courant)->suivant;
            delete aSupprimer;
            return;
        }
        courant = &((*courant)->suivant);
    }
    cout << "Erreur : Adhérent avec le numéro " << numeroAdherent << " non trouvé." << endl;
}

// Emprunter un livre
void Bibliotheque::emprunterLivre(int codeLivre, int numeroAdherent) {
    Livre* livre = listeLivres;
    while (livre) {
        if (livre->getcode() == codeLivre && livre->getetat() == "libre") {
            Adherent* adherent = listeAdherents;
            while (adherent) {
                if (adherent->getnumero() == numeroAdherent) {
                    livre->setetat("emprunté");
                    adherent->emprunter(*livre);
                    cout << "Livre emprunté par l'adhérent : " << adherent->gentom() << endl;
                    return;
                }
                adherent = adherent->suivant;
            }
            cout << "Erreur : Adhérent avec le numéro " << numeroAdherent << " non trouvé." << endl;
            return;
        }
        livre = livre->suivant;
    }
    cout << "Erreur : Livre avec le code " << codeLivre << " non disponible." << endl;
}

// Rendre un livre
void Bibliotheque::rendreLivre(int codeLivre, int numeroAdherent) {
    Livre* livre = listeLivres;
    while (livre) {
        if (livre->getcode() == codeLivre && livre->getetat() == "emprunté") {
            livre->setetat("libre");
            cout << "Livre avec le code " << codeLivre << " retourné avec succès." << endl;
            return;
        }
        livre = livre->suivant;
    }
    cout << "Erreur : Livre avec le code " << codeLivre << " non trouvé ou n'était pas emprunté." << endl;
}

// Getters et Setters
string Bibliotheque::getNom() const { return nom; }
string Bibliotheque::getAdresse() const { return adresse; }
int Bibliotheque::getCode() const { return code; }
Livre* Bibliotheque::getListeLivres() const { return listeLivres; }
Adherent* Bibliotheque::getListeAdherents() const { return listeAdherents; }
int Bibliotheque::getCapaciteMax() const { return capaciteMax; }
int Bibliotheque::getNombreLivres() const { return nombreLivres; }

void Bibliotheque::setNom(const string& nom) { this->nom = nom; }
void Bibliotheque::setAdresse(const string& adresse) { this->adresse = adresse; }
void Bibliotheque::setCode(int code) { this->code = code; }
void Bibliotheque::setCapaciteMax(int capaciteMax) { this->capaciteMax = capaciteMax; }
void Bibliotheque::setNombreLivres(int nombreLivres) { this->nombreLivres = nombreLivres; }
