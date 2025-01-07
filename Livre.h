#ifndef LIVRE_H
#define LIVRE_H
#include BIBLIOTHEQUE_H
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
    public:
        Livfre(int,string,string,string,string,string,string,Bibliotheque);
        Livre();
        void changer_etat(nouvel_etat);
        void afficher_details();
        
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

        
}

#endif
