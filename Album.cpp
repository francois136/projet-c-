#include <iostream>
#include "BandeDessinee.h"

using namespace std;

// Constructeur prenant les attributs spécifiques et appelant le constructeur de Livre
Album::BandeDessinee(string auteur, string titre, string editeur, string isbn, string typeIllustration)
    : Livre(auteur, titre, editeur, isbn), typeIllustration(typeIllustration) {}

// Constructeur de recopie
Album::BandeDessinee(Livre* livre, string typeIllustration)
    : Livre(livre), typeIllustration(typeIllustration) {}

// Getter pour le genre
string Album::gettypeillustration() {
    return typeIllustration;
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
