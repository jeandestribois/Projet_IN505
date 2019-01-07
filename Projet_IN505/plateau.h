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
    Joueur j1, j2;
    int xJ1, yJ1;       // L'indice en x et en y du joueur
    int xJ2, yJ2;
    Pixel tabPixel[LARGEUR_PLA][HAUTEUR_PLA];
    int quiJoue;
    int compteurPas;

public:
    Plateau();
    ~Plateau();
    int getXJ1();
    int getYJ1();
    int getXJ2();
    int getYJ2();
    int setPosJ1(int i, int j); // renvoit 1 lors du succes, 0 lors de l'echec
    int setPosJ2(int i, int j);
    int getQuiJoue();
    void setQuiJoue(int q);
    void remettreCompteurPas();
    Pixel *getPixel(int i, int j);
};

#endif // PLATEAU_H
