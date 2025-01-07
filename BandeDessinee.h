#ifndef BANDEDESSINEED_H_
#define BANDEDESSINEE_H_
#include <iostream>
using namespace std;
#include "Livre.h"

class BandeDessinee:
		public Livre {
    private:
        string dessinateur ;     // Nom de l'illustrateur
    public:
        BandeDessinee(string auteur, string titre, string editeur, string isbn, string dessinateur);
        BandeDessinee(Livre& livre, string& dessinateur); // Constructeur de recopie

        string getDessinateur(); //getter
        void setDessinateur(string); //setter
        
        // Méthode pour afficher les détails spécifiques à une bande dessinée
        void afficher_details();

        // Destructeur
        virtual ~BandeDessinee();
};

#endif /* BANDEDESSINEE_H_ */
