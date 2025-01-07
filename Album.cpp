#include <iostream>
#include "BandeDessinee.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
Album::BandeDessinee(string auteur, string titre, string editeur, string isbn, string dessinateur)
    : Livre(auteur, titre, editeur, isbn), dessinateur(dessinateur) {}

// Constructeur de recopie
Album::BandeDessinee(Livre* livre, string dessinateur)
    : Livre(livre), dessinateur(dessinateur) {}

// Getter pour le genre
string Album::getTypeIllustration() {
    return dessinateur;
}

// Setter pour le genre
void Album::settypeIllustration(string nouveautype) {
	typeIllustration = nouveautype;
}

// Afficher les détails spécifiques à une bande dessinée
void Album::afficher_details() {
    Livre::afficher_details(); // Appel de la méthode de la classe de base
    cout << "Dessinateur : " << dessinateur << endl;
}

// Destructeur
Album::~Album() {}
