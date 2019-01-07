#ifndef JOUEUR_H
#define JOUEUR_H


class Joueur
{
private:
    int pointVie;
    int degatArme;
    int xJoueur, yJoueur;       // L'indice en x et en y du joueurÒ
public:
    Joueur();

    int getXJoueur();
    int getYJoueur();

    void setXJoueur(int x);
    void setYJoueur(int y);
    ~Joueur();
};

#endif // JOUEUR_H
