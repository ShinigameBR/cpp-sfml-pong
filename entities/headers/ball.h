#ifndef BALL_H
#define BALL_H

#include <cmath>
#include "../../components/headers/visible_object.h"
#include "player.h"

class Ball : public VisibleObject
{
public:
    Ball(Rect<float> constraints);
    void update(float timeElapsed);
    void collideWith(VisibleObject *target);

private:
    bool isOut;
    int _angle;
    float _speed;
    float _maxSpeed = 1800.0f;
    Rect<float> _constraints;
};
#endif