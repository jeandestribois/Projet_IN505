#include "joueur.h"

Joueur::Joueur()
{
    pointVie=1000;
    degatArme=100;
}

int Joueur::getXJoueur()
{
    return xJoueur;
}

int Joueur::getYJoueur()
{
    return yJoueur;
}

void Joueur::setXJoueur(int x)
{
    xJoueur=x;
}

void Joueur::setYJoueur(int y)
{
    yJoueur=y;
}

Joueur::~Joueur() {}
