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
        void changer_etat(nouvel_etat);
        void afficher_details();
        
        int getcode();
        string getauteur();
        string gettitre();
        string getediteur();
        string getisbn();
        string getpublics();
        string getetat();
        string getbibliotheque();

        string setetat();
        
}

#endif
