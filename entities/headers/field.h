#ifndef FIELD_H
#define FIELD_H

#include "../../components/headers/visible_object.h"

class Field : public VisibleObject
{
public:
    Field();
    void update(float timeElapsed);
};
#endif
