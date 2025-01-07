#ifndef LIVRE_H
#define LIVRE_H
using namespace std;

class Livre{
    protected:
        int code;
        string auteur;
        string titre;
        string editeur;
        string isbn;
        string publics;
        strign etat;
        Bibliotheque bibliothequeOrigine;
    public:
        changer_etat(nouvel_etat);
        afficher_details();
}

#endif
