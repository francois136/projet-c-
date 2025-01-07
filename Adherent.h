#ifndef ADHERENT_H
#include ADHERENT_H
#include <string>
using namespace std;

class Adherent{
  private:
    string nom;
    string prenom;
    string adresse;
    int numero;
    Bibliotheque bibliotheque;
    Livre* Livresempruntes;
    int maxLivres;
  public:
    Adherent(string,string,string,int,Bibliotheque,int);
    Adherent();
    void emprunter(int);
    void retourner(int);

    string gentom();
    string getprenom();
    string getadress();
    int getnumero();
    Bibliotheque getbibliotheque();
    Livre* getlivresempruntes();
    int getmaxLivres();

    void sentom(string);
    void setprenom(string);
    void setadress(string);
    void setnumero(int);
    void setbibliotheque(Bibliothéque);
    doid setlivresempruntes(Livre*);
    void setmaxLivres(int);
}

#endif
