#ifndef ALBUM_H
#define ALBUM_H
#include <iostream>
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

class Album : public Livre {
    private:
        string illustration ;
    public:
        Album(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string illustration);
        Album(Livre& livre, string illustration);
        string getillustration();
        void setsillustration(string);
        void virtual afficher_details();
        virtual ~Album();
};

#endif
