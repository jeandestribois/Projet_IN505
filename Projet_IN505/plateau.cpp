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
    // Joueur 1
    xJ1=rand()%LARGEUR_PLA;
    yJ1=rand()%HAUTEUR_PLA;
    while(tabPixel[xJ1][yJ1].getElement()->getType() != _LIBRE)
    {
        xJ1=rand()%LARGEUR_PLA;
        yJ1=rand()%HAUTEUR_PLA;
    }
    tabPixel[xJ1][yJ1].getElement()->setType(_JOUEUR);

    //Joueur 2
    xJ2=rand()%LARGEUR_PLA;
    yJ2=rand()%HAUTEUR_PLA;
    while(tabPixel[xJ2][yJ2].getElement()->getType() != _LIBRE)
    {
        xJ2=rand()%LARGEUR_PLA;
        yJ2=rand()%HAUTEUR_PLA;
    }
    tabPixel[xJ2][yJ2].getElement()->setType(_JOUEUR);
    compteurPas=0;

    quiJoue=1; // On definit le joueur qui joue en premier
}

Pixel *Plateau::getPixel(int i, int j)
{
    return &tabPixel[i][j];
}

int Plateau::getXJ1()
{
    return xJ1;
}

int Plateau::getYJ1()
{
    return yJ1;
}

int Plateau::getXJ2()
{
    return xJ2;
}

int Plateau::getYJ2()
{
    return yJ2;
}

int Plateau::getQuiJoue()
{
    return quiJoue;
}

void Plateau::setQuiJoue(int q)
{
    quiJoue=q;
}

void Plateau::remettreCompteurPas()
{
    compteurPas=0;
}

int Plateau::setPosJ1(int i, int j)
{
    if(i==xJ1)  // Si le joueur bouge verticalement
    {
        if(j>=0 && j<HAUTEUR_PLA && tabPixel[i][j].getElement()->getType()==_LIBRE && compteurPas<3)     // Si il ne se trouve pas au bord
        {                                                                              // et que la case est libre
            tabPixel[xJ1][yJ1].getElement()->setType(_LIBRE);   // L'ancien pixel devient libre
            xJ1=i;
            yJ1=j;
            tabPixel[xJ1][yJ1].getElement()->setType(_JOUEUR);  // Le nouveau est remplacé par le joueur
            compteurPas++;
            return 1;
        }
    }
    else if(j==yJ1)   // Si le joueur bouge horizontalement
    {
        if(i>=0 && i<LARGEUR_PLA && tabPixel[i][j].getElement()->getType()==_LIBRE && compteurPas<3)
        {
            tabPixel[xJ1][yJ1].getElement()->setType(_LIBRE);
            xJ1=i;
            yJ1=j;
            tabPixel[xJ1][yJ1].getElement()->setType(_JOUEUR);
            compteurPas++;
            return 1;
        }
    }
    return 0;
}

int Plateau::setPosJ2(int i, int j)
{
    if(i==xJ2)  // Si le joueur bouge verticalement
    {
        if(j>=0 && j<HAUTEUR_PLA && tabPixel[i][j].getElement()->getType()==_LIBRE && compteurPas<3)     // Si il ne se trouve pas au bord
        {                                                                              // et que la case est libre
            tabPixel[xJ2][yJ2].getElement()->setType(_LIBRE);   // L'ancien pixel devient libre
            xJ2=i;
            yJ2=j;
            tabPixel[xJ2][yJ2].getElement()->setType(_JOUEUR);  // Le nouveau est remplacé par le joueur
            compteurPas++;
            return 1;
        }
    }
    else if(j==yJ2)   // Si le joueur bouge horizontalement
    {
        if(i>=0 && i<LARGEUR_PLA && tabPixel[i][j].getElement()->getType()==_LIBRE && compteurPas<3)
        {
            tabPixel[xJ2][yJ2].getElement()->setType(_LIBRE);
            xJ2=i;
            yJ2=j;
            tabPixel[xJ2][yJ2].getElement()->setType(_JOUEUR);
            compteurPas++;
            return 1;
        }
    }
    return 0;
}

Plateau::~Plateau() {}
