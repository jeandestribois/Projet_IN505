#include "element.h"

Element::Element()
{
    type = _LIBRE;
}

Element::Element(type_element t)
{
    type=t;
}

type_element Element::getType()
{
    return type;
}

int Element::getPointVie()
{
    return pointVie;
}

void Element::setType(type_element t)
{
    type=t;
}


Element::~Element() {}


