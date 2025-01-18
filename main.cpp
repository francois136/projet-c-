#include <iostream>
#include "Bibliotheque.h"
#include "Adherent.h"
#include "Roman.h"
#include "BandeDessinee.h"
#include "Recueil_Poemes.h"
#include "PieceTheatre.h"
#include "Album.h"

using namespace std;

void testerBibliotheque() {
    // Créer des instances de Bibliotheque
    Bibliotheque biblio1("Biblio1", "123 Rue des Livres", 101, 10);
    Bibliotheque biblio2("Biblio2", "456 Avenue des Lettres", 102, 5);

    // Créer des livres
    Roman roman1(1, "Auteur1", "Titre1", "Editeur1", "ISBN1", "Public1", "Disponible", biblio1, "Fiction");
    BandeDessinee bd1(2, "Auteur2", "Titre2", "Editeur2", "ISBN2", "Public2", "Disponible", biblio1, "Dessinateur1");
    Recueil_Poemes recueil1(3, "Auteur3", "Titre3", "Editeur3", "ISBN3", "Public3", "Disponible", biblio1, "Format1");
    PieceTheatre piece1(4, "Auteur4", "Titre4", "Editeur4", "ISBN4", "Public4", "Disponible", biblio1, "17e siècle");
    Album album1(5, "Auteur5", "Titre5", "Editeur5", "ISBN5", "Public5", "Disponible", biblio1, "Illustration1");

    // Ajouter des livres à la bibliothèque
    biblio1.ajouterLivre(&roman1);
    biblio1.ajouterLivre(&bd1);
    biblio1.ajouterLivre(&recueil1);
    biblio1.ajouterLivre(&piece1);
    biblio1.ajouterLivre(&album1);

    // Afficher les livres
    biblio1.afficherLivres();

    // Créer des adhérents
    Adherent adherent1("Nom1", "Prenom1", "Adresse1", 1001, biblio1, 3);
    Adherent adherent2(biblio1);

    // Ajouter des adhérents à la bibliothèque
    biblio1.ajouterAdherent(&adherent1);
    biblio1.ajouterAdherent(&adherent2);

    // Emprunter des livres
    adherent1.emprunter(1);  // Emprunter Roman1
    adherent1.emprunter(2);  // Emprunter BD1
    adherent2.emprunter(3);  // Emprunter Recueil1

    // Afficher les détails après emprunt
    cout << "\nDétails après emprunt:" << endl;
    biblio1.afficherLivres();

    // Retourner des livres
    adherent1.retourner(1);  // Retourner Roman1
    adherent2.retourner(3);  // Retourner Recueil1

    // Afficher les détails après retour des livres
    cout << "\nDétails après retour:" << endl;
    biblio1.afficherLivres();

    // Supprimer un livre
    biblio1.supprimerLivre(5);  // Supprimer Album1

    // Afficher les détails après suppression d'un livre
    cout << "\nDétails après suppression:" << endl;
    biblio1.afficherLivres();

    // Acheter un livre (si possible)
    try {
        biblio1.acheterLivre(&roman1);  // Déjà présent, exemple
    } catch (const overflow_error& e) {
        cout << "\nErreur d'achat: " << e.what() << endl;
    }

    // Demander un livre d'une autre bibliothèque
    try {
        biblio2.ajouterLivre(new Roman(6, "Auteur6", "Titre6", "Editeur6", "ISBN6", "Public6", "Disponible", biblio2, "Fiction"));
        biblio1.demanderLivreAutreBibliotheque("ISBN6", biblio2);
    } catch (const runtime_error& e) {
        cout << "\nErreur de demande de livre: " << e.what() << endl;
    }

    // Rendre livres prêtés
    biblio1.rendreLivresPretes();
}

void afficherDetailsLivre(Livre* livre) {
    livre->afficher_details();
}

int main() {
    cout << "Tests des méthodes des classes de bibliothèque et de livres:" << endl;

    // Tester les opérations de la bibliothèque
    testerBibliotheque();

    // Créer et afficher les détails des livres
    Bibliotheque biblio1("Biblio1", "123 Rue des Livres", 101, 10);
    Roman roman1(1, "Auteur1", "Titre1", "Editeur1", "ISBN1", "Public1", "Disponible", biblio1, "Fiction");
    BandeDessinee bd1(2, "Auteur2", "Titre2", "Editeur2", "ISBN2", "Public2", "Disponible", biblio1, "Dessinateur1");
    Recueil_Poemes recueil1(3, "Auteur3", "Titre3", "Editeur3", "ISBN3", "Public3", "Disponible", biblio1, "Format1");
    PieceTheatre piece1(4, "Auteur4", "Titre4", "Editeur4", "ISBN4", "Public4", "Disponible", biblio1, "17e siècle");
    Album album1(5, "Auteur5", "Titre5", "Editeur5", "ISBN5", "Public5", "Disponible", biblio1, "Illustration1");

    cout << "\nDétails des livres:" << endl;
    afficherDetailsLivre(&roman1);
    afficherDetailsLivre(&bd1);
    afficherDetailsLivre(&recueil1);
    afficherDetailsLivre(&piece1);
    afficherDetailsLivre(&album1);

    return 0;
}
