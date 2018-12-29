#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QPixmap>

#include "variables_global_types.h"
#include "plateau.h"

class Fenetre : public QWidget
{
protected:
    Plateau plateau;
    int pixelOrigineX, pixelOrigineY;

public:
    Fenetre();
    ~Fenetre();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
};

#endif // FENETRE_H
