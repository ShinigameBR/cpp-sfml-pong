#ifndef BALL_H
#define BALL_H

#include <cmath>
#include "../../components/headers/visible_object.h"

class Ball : public VisibleObject
{
public:
    Ball(Rect<float> constraints);
    void update(float timeElapsed);

private:
    int _angle;
    float _speed;
    Rect<float> _constraints;
};
#endif