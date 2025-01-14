#ifndef ALBUM_H_
#define ALBUM_H_
#include <iostream>
using namespace std;
#include "Livre.h"

class Album:
		public Livre {
    private:
        string illustration ;     // Nom de l'illustrateur
    public:
        Album(string auteur, string titre, string editeur, string isbn, string illustration);
        Album(Livre& livre, string& illustration); // Constructeur de recopie

        string getillustration(); //getter
        void setsillustration(string); //setter

        // Destructeur
        virtual ~Album();
};

#endif /* ALBUM_H_ */
