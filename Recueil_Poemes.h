#ifndef RECUEIL_POEMES_H
#define RECUEIL_POEMES_H
#include <iostream>
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

class Recueil_Poemes : public Livre {
    private:
        string formatPoeme;
    public:
        Recueil_Poemes(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string formatPoeme);
        Recueil_Poemes(Livre& livre, string formatPoeme);
        string getformatPoeme();
        void setformatPoeme(string);
        void virtual afficher_details();
        virtual ~Recueil_Poemes();
};

#endif
