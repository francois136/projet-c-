#ifndef RECUEIL_POEMES_H_
#define RECUEIL_POEMES_H_
#include <iostream>
using namespace std;
#include "Livre.h"

class Receuil_Poemes:
		public Livre {
    private:
        string format_poeme ;     // Nom de l'illustrateur
    public:
        Recueil_Poemes(string auteur, string titre, string editeur, string isbn, string format_poeme);
        Recueil_Poemes(Livre& livre, string& format_poeme); // Constructeur de recopie

        string getformat_poeme(); //getter
        void setformat_poeme(string); //setter
        
        // Méthode pour afficher les détails spécifiques à une bande dessinée
        void afficher_details();

        // Destructeur
        virtual ~Recueil_Poemes();
};

#endif /* RECUEIL_POEMES_H_ */
