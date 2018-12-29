#include "fenetre.h"

Fenetre::Fenetre() : QWidget()
{
    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(LARGEUR_FEN, HAUTEUR_FEN);
    pixelOrigineX=0;
    pixelOrigineY=0;
}

void Fenetre::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::white);
    for(int i=pixelOrigineX; i<LARGEUR_PLA; i++)
    {
        for(int j=pixelOrigineY; j<HAUTEUR_PLA; j++)
        {
            p.fillRect((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, COTE_PIX, COTE_PIX, QColor(164,164,164));
            p.drawRect((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, COTE_PIX, COTE_PIX);
            if (plateau.getPixel(i,j)->getElement()->getType() == _ARBRE)
            {
                p.drawImage((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, QImage("../../../../Projet_IN505/images/tree.png"));
            }
            else if(plateau.getPixel(i,j)->getElement()->getType() == _JOUEUR)
            {
                p.drawImage((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, QImage("../../../../Projet_IN505/images/joueur.png"));
            }
        }
    }
}

void Fenetre::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)      // On verifie la direction
    {
        if(plateau.setPosJoueur(plateau.getXJoueur(), plateau.getYJoueur()-1)
                && pixelOrigineY > 0
                && (plateau.getYJoueur()-pixelOrigineY)*COTE_PIX < 2*COTE_PIX)
        {
            pixelOrigineY--;
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(plateau.setPosJoueur(plateau.getXJoueur(), plateau.getYJoueur()+1)
                && ((HAUTEUR_PLA-pixelOrigineY)*COTE_PIX > HAUTEUR_FEN)
                && (plateau.getYJoueur()-pixelOrigineY)*COTE_PIX > HAUTEUR_FEN-2*COTE_PIX)
        {
            pixelOrigineY++;
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(plateau.setPosJoueur(plateau.getXJoueur()+1, plateau.getYJoueur())
                && ((LARGEUR_PLA-pixelOrigineX)*COTE_PIX > LARGEUR_FEN)
                && (plateau.getXJoueur()-pixelOrigineX)*COTE_PIX > LARGEUR_FEN-2*COTE_PIX)
        {
            pixelOrigineX++;
        }
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(plateau.setPosJoueur(plateau.getXJoueur()-1, plateau.getYJoueur())
                && (pixelOrigineX > 0)
                && (plateau.getXJoueur()-pixelOrigineX)*COTE_PIX < 2*COTE_PIX)
        {
            pixelOrigineX--;
        }
    }
    update();
}

Fenetre::~Fenetre() {}

