#ifndef BIBLIOTHEQUE_H_
#define BIBLIOTHEQUE_H_

#include <iostream>
#include <string>
#include <list>
#include "Livre.h"
#include "Adherent.h"

using namespace std;

class Bibliotheque {
private:
    string nom;                             // Nom de la bibliothèque
    string adresse;                         // Adresse de la bibliothèque
    int code;                               // Code unique de la bibliothèque
    Livre* listeLivres;                // Liste chaînée de livres stockés
    Adherent* listeAdherents;          // Liste chaînée des adhérents inscrits
    int capaciteMax;                        // Capacité maximale de la bibliothèque (par défaut 100)
    int nombreLivres;                       // Nombre de livres disponibles dans la bibliothèque (par défaut 15)

public:
    // Constructeurs
    Bibliotheque();
    Bibliotheque(const string& nom, const string& adresse, int code, int capaciteMax = 100);

    // Méthodes
    void ajouterLivre(const Livre& livre);                 // Ajouter un livre à la bibliothèque
    void afficherLivres() const;                           // Afficher tous les livres
    void acheterLivre(const Livre& livre);                 // Acheter un livre
    void supprimerLivre(int codeLivre);                    // Supprimer un livre par son code
    void ajouterAdherent(const Adherent& adherent);        // Ajouter un adhérent
    void supprimerAdherent(int numeroAdherent);            // Supprimer un adhérent par son numéro
    void emprunterLivre(int codeLivre, int numeroAdherent); // Permettre à un adhérent d'emprunter un livre
    void rendreLivre(int codeLivre, int numeroAdherent);   // Enregistrer le retour d’un livre emprunté
    void demanderLivreAutreBibliotheque(const string& isbn, Bibliotheque& bibliothequeDest); // Demander un livre
    void rendreLivresPretes();                             // Identifier et récupérer les livres prêtés qui ne sont pas empruntés

    // Getters
    string getNom() const;
    string getAdresse() const;
    int getCode() const;
    Livre* getListeLivres() const;
    Adherent* getListeAdherents() const;
    int getCapaciteMax() const;
    int getNombreLivres() const;

    // Setters
    void setNom(const string& nom);
    void setAdresse(const string& adresse);
    void setCode(int code);
    void setCapaciteMax(int capaciteMax);
    void setNombreLivres(int nombreLivres);
};

#endif /* BIBLIOTHEQUE_H_ */
