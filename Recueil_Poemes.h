#ifndef RECUEIL_POEMES_H_
#define RECUEIL_POEMES_H_
#include <iostream>
using namespace std;
#include "Livre.h"

class Recueil_Poemes:
		public Livre {
    private:
        string formatPoeme ;     // Nom de l'illustrateur
    public:
        Recueil_Poemes(string auteur, string titre, string editeur, string isbn, string formatPoeme);
        Recueil_Poemes(Livre& livre, string& formatPoeme); // Constructeur de recopie

        string getformatPoeme(); //getter
        void setformatPoeme(string); //setter

        // Destructeur
        virtual ~Recueil_Poemes();
};

#endif /* RECUEIL_POEMES_H_ */
