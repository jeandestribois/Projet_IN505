#ifndef PLATEAU_H
#define PLATEAU_H

#include <cstdlib>
#include <ctime>
#include <QObject>
#include "pixel.h"
#include "variables_global_types.h"
#include "joueur.h"

class Plateau : public QObject
{
protected:
    int largeur;
    int hauteur;
    int xJoueur, yJoueur;       // L'indice en x et en y du joueur
    Pixel tabPixel[LARGEUR_PLA][HAUTEUR_PLA];

public:
    Plateau();
    ~Plateau();
    int getXJoueur();
    int getYJoueur();
    int setPosJoueur(int i, int j); // renvoit 1 lors du succes, 0 lors de l'echec
    Pixel *getPixel(int i, int j);
};

#endif // PLATEAU_H
