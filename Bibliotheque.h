#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include <iostream>
#include <string>
#include "Livre.h"
#include "Adherent.h"
using namespace std;

class Bibliotheque {
    private:
        string nom;
        string adresse;
        int code;
        Livre* listeLivres;        // Liste chaînée de livres stockés
        Adherent* listeAdherents;  // Liste chaînée des adhérents inscrits
        int capaciteMax;
        int nombreLivres;
    public:
        Bibliotheque();
        Bibliotheque(string nom,string adresse,int code, int capaciteMax);
        void ajouterLivre(Livre* livre);
        void afficherLivres();
        void acheterLivre(Livre* livre);
        void supprimerLivre(int codeLivre);
        void ajouterAdherent(Adherent* adherent);
        void supprimerAdherent(int numeroAdherent);
        void emprunterLivre(int codeLivre, int numeroAdherent);
        void rendreLivre(int codeLivre, int numeroAdherent);
        void demanderLivreAutreBibliotheque(string isbn, Bibliotheque bibliothequeDest);
        void rendreLivresPretes();

        string getNom();
        string getAdresse();
        int getCode();
        Livre* getListeLivres();
        Adherent* getListeAdherents();
        int getCapaciteMax();
        int getNombreLivres();

        void setNom(string nom);
        void setAdresse(string adresse);
        void setCode(int code);
        void setCapaciteMax(int capaciteMax);
        void setNombreLivres(int nombreLivres);
};

#endif
