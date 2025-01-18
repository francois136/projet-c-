#ifndef ROMAN_H
#define ROMAN_H
#include <iostream>
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

class Roman : public Livre {
private:
    string genre;
public:
    Roman(int code, string auteur, string titre, string editeur, string isbn, string publics, string etat, Bibliotheque bibliothequeOrigine, string genre);
    Roman(Livre& livre, string genre);
    string getgenre();
    void setgenre(string);
    void virtual afficher_details();
    virtual ~Roman();
};

#endif
