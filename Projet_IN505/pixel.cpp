#include "pixel.h"

Pixel::Pixel()
{
    tailleCote=COTE_PIX;
    element = new Element(_LIBRE);
}

Element *Pixel::getElement()
{
    return element;
}

Pixel::~Pixel()
{
    delete element;
}
