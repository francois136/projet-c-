#include "Bibliotheque.h"
#include "Livre.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

// Constructeur par défaut
Bibliotheque::Bibliotheque() : nom(""), adresse(""), code(0), capaciteMax(100), nombreLivres(15) {}

// Constructeur paramétré
Bibliotheque::Bibliotheque(string nom, string adresse, int code) 
    : nom(nom), adresse(adresse), code(code), capaciteMax(100), nombreLivres(15) {}

// Ajouter un livre
void Bibliotheque::ajouterLivre(Livre* livre) {
    if (nombreLivres >= capaciteMax) {
        cout << "Erreur : La capacité maximale de la bibliothèque a été atteinte." << endl;
        return;
    }
    listeLivres.push_back(livre);
    nombreLivres++;
    cout << "Livre \"" << livre->getTitre() << "\" ajouté avec succès." << endl;
}

// Afficher tous les livres
void Bibliotheque::afficherLivres() {
    if (listeLivres.empty()) {
        cout << "La bibliothèque ne contient aucun livre pour le moment." << endl;
    } else {
        cout << "Livres dans la bibliothèque \"" << nom << "\":" << endl;
        for (const auto& livre : listeLivres) {
            cout << "Code: " << livre->getCode() 
                 << ", Titre: " << livre->getTitre() 
                 << ", État: " << livre->getEtat() << endl;
        }
    }
}

// Acheter un livre
void Bibliotheque::acheterLivre(Livre* livre) {
    cout << "La bibliothèque \"" << nom << "\" achète le livre \"" << livre->getTitre() << "\"." << endl;
    ajouterLivre(livre);
}

// Supprimer un livre par code
void Bibliotheque::supprimerLivre(int codeLivre) {
    auto it = find_if(listeLivres.begin(), listeLivres.end(), 
                      [codeLivre](Livre* livre) { return livre->getCode() == codeLivre; });

    if (it != listeLivres.end()) {
        cout << "Livre \"" << (*it)->getTitre() << "\" supprimé avec succès." << endl;
        listeLivres.erase(it);
        nombreLivres--;
    } else {
        cout << "Erreur : Aucun livre avec le code " << codeLivre << " trouvé." << endl;
    }
}

// Ajouter un adhérent
void Bibliotheque::ajouterAdherent(Adherent* adherent) {
    listeAdherents.push_back(adherent);
    cout << "Adhérent \"" << adherent->getNom() << "\" ajouté avec succès." << endl;
}

// Supprimer un adhérent par numéro
void Bibliotheque::supprimerAdherent(int numeroAdherent) {
    auto it = find_if(listeAdherents.begin(), listeAdherents.end(), 
                      [numeroAdherent](Adherent* adherent) { return adherent->getNumero() == numeroAdherent; });

    if (it != listeAdherents.end()) {
        cout << "Adhérent \"" << (*it)->getNom() << "\" supprimé avec succès." << endl;
        listeAdherents.erase(it);
    } else {
        cout << "Erreur : Aucun adhérent avec le numéro " << numeroAdherent << " trouvé." << endl;
    }
}

// Emprunter un livre
void Bibliotheque::emprunterLivre(int codeLivre, int numeroAdherent) {
    auto adherent = find_if(listeAdherents.begin(), listeAdherents.end(), 
                            [numeroAdherent](Adherent* a) { return a->getNumero() == numeroAdherent; });

    if (adherent == listeAdherents.end()) {
        cout << "Erreur : Adhérent avec le numéro " << numeroAdherent << " introuvable." << endl;
        return;
    }

    auto livre = find_if(listeLivres.begin(), listeLivres.end(), 
                         [codeLivre](Livre* l) { return l->getCode() == codeLivre && l->getEtat() == "libre"; });

    if (livre != listeLivres.end()) {
        (*livre)->setEtat("emprunté");
        cout << "Livre \"" << (*livre)->getTitre() << "\" emprunté par l'adhérent \"" << (*adherent)->getNom() << "\"." << endl;
    } else {
        cout << "Erreur : Livre avec le code " << codeLivre << " introuvable ou non disponible." << endl;
    }
}

// Rendre un livre
void Bibliotheque::rendreLivre(int codeLivre, int numeroAdherent) {
    auto livre = find_if(listeLivres.begin(), listeLivres.end(), 
                         [codeLivre](Livre* l) { return l->getCode() == codeLivre && l->getEtat() == "emprunté"; });

    if (livre != listeLivres.end()) {
        (*livre)->setEtat("libre");
        cout << "Livre \"" << (*livre)->getTitre() << "\" retourné avec succès." << endl;
    } else {
        cout << "Erreur : Livre avec le code " << codeLivre << " non trouvé ou n'était pas emprunté." << endl;
    }
}

// Demander un livre d'une autre bibliothèque
void Bibliotheque::demanderLivreAutreBibliotheque(string isbn, Bibliotheque& autreBibliotheque) {
    auto livre = find_if(autreBibliotheque.listeLivres.begin(), autreBibliotheque.listeLivres.end(), 
                         [isbn](Livre* l) { return l->getISBN() == isbn && l->getEtat() == "libre"; });

    if (livre != autreBibliotheque.listeLivres.end()) {
        Livre* copieLivre = new Livre(**livre);
        copieLivre->setEtat("emprunté");
        ajouterLivre(copieLivre);
        (*livre)->setEtat("prêté");
        cout << "Livre avec ISBN " << isbn << " emprunté depuis une autre bibliothèque." << endl;
    } else {
        cout << "Erreur : Livre avec ISBN " << isbn << " non disponible dans l'autre bibliothèque." << endl;
    }
}

// Récupérer les livres prêtés
void Bibliotheque::rendreLivresPretes() {
    for (auto livre : listeLivres) {
        if (livre->getEtat() == "prêté") {
            livre->setEtat("libre");
            cout << "Livre \"" << livre->getTitre() << "\" récupéré avec succès." << endl;
        }
    }
}

// Getters et Setters
string Bibliotheque::getNom() { return nom; }
string Bibliotheque::getAdresse() { return adresse; }
int Bibliotheque::getCode() { return code; }
int Bibliotheque::getNombreLivres() { return nombreLivres; }
int Bibliotheque::getCapaciteMax() { return capaciteMax; }

