#ifndef PIECETHEATRE_H
#define PIECETHEATRE_H
#include <iostream>
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

class PieceTheatre : public Livre {
    private:
        string siecle;
    public:
        PieceTheatre(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string siecle);
        PieceTheatre(Livre& livre, string siecle);
        string getsiecle();
        void setsiecle(string);
        void virtual afficher_details();
        virtual ~PieceTheatre();
};

#endif