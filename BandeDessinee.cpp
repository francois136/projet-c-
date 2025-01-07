#include <iostream>
#include "BandeDessinee.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
BandeDessinee::BandeDessinee(string auteur, string titre, string editeur, string isbn, string dessinateur)
    : Livre(auteur, titre, editeur, isbn), dessinateur(dessinateur) {}

// Constructeur de recopie
BandeDessinee::BandeDessinee(Livre* livre, string dessinateur)
    : Livre(livre), dessinateur(dessinateur) {}

// Getter pour le genre
string BandeDessinee::getDessinateur() {
    return dessinateur;
}

// Setter pour le genre
void BandeDessinee::setDessinateur(string nouveauDessinateur) {
	dessinateur = nouveauDessinateur;
}

// Afficher les détails spécifiques à une bande dessinée
void BandeDessinee::afficher_details() {
    Livre::afficher_details(); // Appel de la méthode de la classe de base
    cout << "Dessinateur : " << dessinateur << endl;
}

// Destructeur
BandeDessinee::~BandeDessinee() {}
