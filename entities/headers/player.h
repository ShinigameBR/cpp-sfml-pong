#ifndef PLAYER_H
#define PLAYER_H

#include "../../components/headers/visible_object.h"

class Player : public VisibleObject
{
public:
    Player(float constraintTop, float constraintBottom);
    void handleInput(Event *event);
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