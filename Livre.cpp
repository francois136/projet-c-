#include "Livre.h"
#include <iostream>
using namespace std;

void Livre::changer_etat(nouvel_etat){
    etat = nouvel_etat;
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
