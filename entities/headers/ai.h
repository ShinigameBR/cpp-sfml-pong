#ifndef AI_H
#define AI_H

#include "../../components/headers/pong.h"
#include "../../components/headers/visible_object.h"
#include "ball.h"

class Ai : public VisibleObject
{
public:
    Ai(float constraintTop, float constraintBottom);
    void runAI();
    void update(float timeElapsed);

private:
    enum Direction
    {
        DIRECTION_NONE,
        DIRECTION_UP,
        DIRECTION_DOWN
    };
    Direction _direction = DIRECTION_NONE;
    float _speed = 800.0f;
    float _constraintTop;
    float _constraintBottom;
};

#endif