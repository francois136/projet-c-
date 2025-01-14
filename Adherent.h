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
    void setbibliotheque(Biblioteque);
    void setlivresempruntes(list<Livre>);
    void setmaxLivres(int);
}

#endif
