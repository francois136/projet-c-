#include <iostream>

template <typename T>
void afficher_details_template(T& livre) {
    cout << "Auteur: " << livre.getauteur() << endl;
    cout << "Titre: " << livre.gettitre() << endl;
    cout << "Editeur: " << livre.getediteur() << endl;
    cout << "ISBN: " << livre.getisbn() << endl;
    cout << "Publics: " << livre.getpublics() << endl;
    cout << "Etat: " << livre.getetat() << endl;
    cout << "Bibliotheque d'origine: " << livre.getbibliotheque().getNom() << endl;
}