#ifndef BIBLIOTHEQUE_H_
#define BIBLIOTHEQUE_H_
#include <iostream>
using namespace std;
#include "Livre.h"
#include <stdexcept>
class Livre;

class Bibliotheque{
    private:
        String nom;
        String adresse;
        int code;
        int capaciteMax;
        int nombreLivres;
