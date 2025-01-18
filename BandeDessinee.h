#ifndef BANDEDESSINE_H
#define BANDEDESSINE_H
#include "Bibliotheque.h"
#include <iostream>
#include "Livre.h"
using namespace std;

class BandeDessinee : public Livre{
    private:
        string dessinateur;
    public:
        BandeDessinee(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string dessinateur);
        BandeDessinee(Livre&,string);
        string getDessinateur();
        void setDessinateur(string);
        void virtual afficher_details();
        virtual ~BandeDessinee();
};

#endif
