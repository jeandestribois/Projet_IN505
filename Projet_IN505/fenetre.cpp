#include "fenetre.h"

Fenetre::Fenetre() : QWidget()
{
    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(LARGEUR_FEN, HAUTEUR_FEN);
    pixelOrigineX=plateau.getXJ1()-3;
    pixelOrigineY=plateau.getYJ1()-3;
}

void Fenetre::paintEvent(QPaintEvent *)
{
    if(pixelOrigineX < 0) pixelOrigineX=0;
    if(pixelOrigineY < 0) pixelOrigineY=0;
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
                p.drawImage((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, QImage("../../../../Projet_IN505/images/arbre.png"));
            }
            else if(plateau.getPixel(i,j)->getElement()->getType() == _JOUEUR)
            {
                if(i==plateau.getXJ1() && j==plateau.getYJ1())
                {
                    p.drawImage((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, QImage("../../../../Projet_IN505/images/joueur1.png"));
                }
                else p.drawImage((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, QImage("../../../../Projet_IN505/images/joueur2.png"));
            }
            else if(plateau.getPixel(i,j)->getElement()->getType() == _ROCHER)
            {
                p.drawImage((i-pixelOrigineX)*COTE_PIX, (j-pixelOrigineY)*COTE_PIX, QImage("../../../../Projet_IN505/images/rocher.png"));
            }
        }
    }
}

void Fenetre::keyPressEvent(QKeyEvent *event)
{
    // Joueur 1
    if(plateau.getQuiJoue() == 1)
    {
        if(event->key() == Qt::Key_Up)      // On verifie la direction
        {
            if(plateau.setPosJ1(plateau.getXJ1(), plateau.getYJ1()-1) // On verifie que la case est libre
                    && pixelOrigineY > 0                                          // Et que le joueur n'est pas au bord
                    && (plateau.getYJ1()-pixelOrigineY)*COTE_PIX < 2*COTE_PIX)
            {
                pixelOrigineY--;
            }
        }
        else if(event->key() == Qt::Key_Down)
        {
            if(plateau.setPosJ1(plateau.getXJ1(), plateau.getYJ1()+1)
                    && ((HAUTEUR_PLA-pixelOrigineY)*COTE_PIX > HAUTEUR_FEN)
                    && (plateau.getYJ1()-pixelOrigineY)*COTE_PIX > HAUTEUR_FEN-2*COTE_PIX)
            {
                pixelOrigineY++;
            }
        }
        else if(event->key() == Qt::Key_Right)
        {
            if(plateau.setPosJ1(plateau.getXJ1()+1, plateau.getYJ1())
                    && ((LARGEUR_PLA-pixelOrigineX)*COTE_PIX > LARGEUR_FEN)
                    && (plateau.getXJ1()-pixelOrigineX)*COTE_PIX > LARGEUR_FEN-2*COTE_PIX)
            {
                pixelOrigineX++;
            }
        }
        else if(event->key() == Qt::Key_Left)
        {
            if(plateau.setPosJ1(plateau.getXJ1()-1, plateau.getYJ1())
                    && (pixelOrigineX > 0)
                    && (plateau.getXJ1()-pixelOrigineX)*COTE_PIX < 2*COTE_PIX)
            {
                pixelOrigineX--;
            }
        }
    }

    // Joueur 2
    if(plateau.getQuiJoue() ==2)
    {
        if(event->key() == Qt::Key_Up)      // On verifie la direction
        {
            if(plateau.setPosJ2(plateau.getXJ2(), plateau.getYJ2()-1) // On verifie que la case est libre
                    && pixelOrigineY > 0                                          // Et que le joueur n'est pas au bord
                    && (plateau.getYJ2()-pixelOrigineY)*COTE_PIX < 2*COTE_PIX)
            {
                pixelOrigineY--;
            }
        }
        else if(event->key() == Qt::Key_Down)
        {
            if(plateau.setPosJ2(plateau.getXJ2(), plateau.getYJ2()+1)
                    && ((HAUTEUR_PLA-pixelOrigineY)*COTE_PIX > HAUTEUR_FEN)
                    && (plateau.getYJ2()-pixelOrigineY)*COTE_PIX > HAUTEUR_FEN-2*COTE_PIX)
            {
                pixelOrigineY++;
            }
        }
        else if(event->key() == Qt::Key_Right)
        {
            if(plateau.setPosJ2(plateau.getXJ2()+1, plateau.getYJ2())
                    && ((LARGEUR_PLA-pixelOrigineX)*COTE_PIX > LARGEUR_FEN)
                    && (plateau.getXJ2()-pixelOrigineX)*COTE_PIX > LARGEUR_FEN-2*COTE_PIX)
            {
                pixelOrigineX++;
            }
        }
        else if(event->key() == Qt::Key_Left)
        {
            if(plateau.setPosJ2(plateau.getXJ2()-1, plateau.getYJ2())
                    && (pixelOrigineX > 0)
                    && (plateau.getXJ2()-pixelOrigineX)*COTE_PIX < 2*COTE_PIX)
            {
                pixelOrigineX--;
            }
        }
    }

    // Pour finir le tour
    if(event->key() == Qt::Key_F)
    {
        if(plateau.getQuiJoue() == 1)
        {
            pixelOrigineX=plateau.getXJ2()-3;
            pixelOrigineY=plateau.getYJ2()-3;
            plateau.setQuiJoue(2);
        }
        else
        {
            pixelOrigineX=plateau.getXJ1()-3;
            pixelOrigineY=plateau.getYJ1()-3;
            plateau.setQuiJoue(1);
        }
        plateau.remettreCompteurPas();
    }
    update();
}

Fenetre::~Fenetre() {}

