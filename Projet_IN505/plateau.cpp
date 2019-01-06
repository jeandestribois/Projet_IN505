#include "plateau.h"

Plateau::Plateau()      // Positionnement aleatoire des éléments du plateau
{
    largeur = LARGEUR_PLA;
    hauteur = HAUTEUR_PLA;

    srand(time(NULL));
    int nbreAlea;

    for(int i=1; i<LARGEUR_PLA; i++)
    {
        for(int j=0; j<HAUTEUR_PLA; j++)
        {
            nbreAlea=rand()%7;
            if(nbreAlea==0) tabPixel[i][j].getElement()->setType(_ARBRE);
            else if(nbreAlea==1) tabPixel[i][j].getElement()->setType(_ROCHER);
            else tabPixel[i][j].getElement()->setType(_LIBRE);
        }
    }
    xJoueur=0;
    yJoueur=2;
    tabPixel[xJoueur][yJoueur].getElement()->setType(_JOUEUR);
    xJoueur=rand()%LARGEUR_PLA;
    yJoueur=rand()%HAUTEUR_PLA;
    while(tabPixel[xJoueur][yJoueur].getElement()->getType() != _LIBRE)
    {
        xJoueur=rand()%LARGEUR_PLA;
        yJoueur=rand()%HAUTEUR_PLA;
    }
    tabPixel[xJoueur][yJoueur].getElement()->setType(_JOUEUR);
}

Pixel *Plateau::getPixel(int i, int j)
{
    return &tabPixel[i][j];
}

int Plateau::getXJoueur()
{
    return xJoueur;
}

int Plateau::getYJoueur()
{
    return yJoueur;
}

int Plateau::setPosJoueur(int i, int j)
{
    if(i==xJoueur)  // Si le joueur bouge verticalement
    {
        if(j>=0 && j<HAUTEUR_PLA && tabPixel[i][j].getElement()->getType()==_LIBRE)     // Si il ne se trouve pas au bord
        {                                                                              // et que la case est libre
            tabPixel[xJoueur][yJoueur].getElement()->setType(_LIBRE);   // L'ancien pixel devient libre
            xJoueur=i;
            yJoueur=j;
            tabPixel[xJoueur][yJoueur].getElement()->setType(_JOUEUR);  // Le nouveau est remplacé par le joueur
            return 1;
        }
    }
    else if(j==yJoueur)   // Si le joueur bouge horizontalement
    {
        if(i>=0 && i<LARGEUR_PLA && tabPixel[i][j].getElement()->getType()==_LIBRE)
        {
            tabPixel[xJoueur][yJoueur].getElement()->setType(_LIBRE);
            xJoueur=i;
            yJoueur=j;
            tabPixel[xJoueur][yJoueur].getElement()->setType(_JOUEUR);
            return 1;
        }
    }
    return 0;
}

Plateau::~Plateau() {}
