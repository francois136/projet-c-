#ifndef PIECETHEATRE_H_
#define PIECETHEATRE_H_
#include <iostream>
using namespace std;
#include "Livre.h"

class PieceTheatre:
		public Livre {
    private:
        string siecle ;     // Nom de l'illustrateur
    public:
        PieceTheatre(string auteur, string titre, string editeur, string isbn, string siecle);
        PieceTheatre(Livre& livre, string& siecle); // Constructeur de recopie

        string getsiecle(); //getter
        void setsiecle(string); //setter

        // Destructeur
        virtual ~PieceTheatre();
};

#endif /* PIECETHEATRE_H_ */
