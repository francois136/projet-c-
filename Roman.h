#ifndef ROMAN_H_
#define ROMAN_H_
#include <iostream>
using namespace std;
#include "Livre.h"

class Roman:
		public Livre {
    private:
        string genre ;     // Nom de l'illustrateur
    public:
        Roman(string auteur, string titre, string editeur, string isbn, string genre);
        Roman(Livre& livre, string& genre); // Constructeur de recopie

        string getgenre(); //getter
        void setgenre(string); //setter

        // Destructeur
        virtual ~Roman();
};

#endif /* ROMAN_H_ */
