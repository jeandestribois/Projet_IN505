#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>

#include "variables_global_types.h"

class Element : QObject
{
protected:
    type_element type;


public:
    Element();
    Element(type_element t);

    virtual type_element getType();
    virtual void setType(type_element t);

    virtual ~Element();
};

#endif // ELEMENT_H
