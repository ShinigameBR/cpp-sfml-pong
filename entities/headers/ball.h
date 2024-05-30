#ifndef BALL_H
#define BALL_H

#include <cmath>
#include "../../components/headers/visible_object.h"
#include "player.h"
#include "ai.h"

class Ball : public VisibleObject
{
public:
    Ball(Rect<float> constraints);
    void update(float timeElapsed);
    void collideWith(VisibleObject *target);
    bool isOut = false;

private:
    int _angle;
    float _speed;
    float _maxSpeed = 1800.0f;
    Rect<float> _constraints;
};

#endif