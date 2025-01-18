#ifndef LIVRE_H
#define LIVRE_H
#include "Bibliotheque.h"
#include <string>
using namespace std;

class Livre{
    protected:
        int code;
        string auteur;
        string titre;
        string editeur;
        string isbn;
        string publics;
        string etat;
        Bibliotheque bibliothequeOrigine;
        Livre* suivant;
    public:
        Livre(int,string,string,string,string,string,string,Bibliotheque);
        Livre(Bibliotheque);
        void changer_etat(string);
        virtual void afficher_details() = 0;
        virtual ~Livre() {};

        int getcode();
        string getauteur();
        string gettitre();
        string getediteur();
        string getisbn();
        string getpublics();
        string getetat();
        Bibliotheque getbibliotheque();

        void setcode(int);
        void setauteur(string);
        void settitre(string);
        void setediteur(string);
        void setisbn(string);
        void setpublics(string);
        void setetat(string);
        void setbibliotheque(Bibliotheque);
    friend class Bibliotheque;
    friend class Adherent;
};

#endif
