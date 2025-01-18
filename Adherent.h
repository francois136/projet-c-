#ifndef ADHERENT_H
#define ADHERENT_H
#include "Bibliotheque.h"
#include <string>
#include <list>
using namespace std;


class Adherent{
  protected:
    string nom;
    string prenom;
    string adresse;
    int numero;
    Bibliotheque bibliotheque;
    list<Livre> Livresempruntes;
    int maxLivres;
    Adherent* suivant;
  public:
    Adherent(string,string,string,int,Bibliotheque,int);
    Adherent(Bibliotheque);
    void emprunter(int);
    void retourner(int);

    string gentom();
    string getprenom();
    string getadress();
    int getnumero();
    Bibliotheque getbibliotheque();
    list<Livre> getlivresempruntes();
    int getmaxLivres();

    void sentnom(string);
    void setprenom(string);
    void setadresse(string);
    void setnumero(int);
    void setbibliotheque(Bibliotheque);
    void setlivresempruntes(list<Livre>);
    void setmaxLivres(int);
    friend class Bibliotheque;
};

#endif
