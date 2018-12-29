#ifndef PIXEL_H
#define PIXEL_H

#include <QObject>
#include "element.h"
#include "variables_global_types.h"

class Pixel : public QObject
{
protected:
    int tailleCote;
    Element *element;

public:
    Pixel();
    Element *getElement();
    ~Pixel();
};

#endif // PIXEL_H
