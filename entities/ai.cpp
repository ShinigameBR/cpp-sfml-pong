#include "./headers/ai.h"

Ai::Ai(float constraintTop, float constraintBottom) : VisibleObject("./assets/player.png")
{
    _constraintTop = constraintTop;
    _constraintBottom = constraintBottom;
}

void Ai::runAI()
{
    Ball *ball = dynamic_cast<Ball *>(Pong::getState()->getObjectManager()->get("ball"));
    if (ball->getBottom() > getBottom())
    {
        _direction = DIRECTION_DOWN;
    }
    else if (ball->getTop() < getTop())
    {
        _direction = DIRECTION_UP;
    }
    else
    {
        _direction = DIRECTION_NONE;
    }
}

void Ai::update(float timeElapsed)
{
    runAI();

    float velocity = 0.0f;

    if (_direction == DIRECTION_UP)
    {
        velocity = _speed * -1;
    }
    else if (_direction == DIRECTION_DOWN)
    {
        velocity = _speed;
    }

    move(0, velocity * timeElapsed);

    sf::Vector2 pos = getPosition();
    if (pos.y < _constraintTop)
    {
        setPosition(pos.x, _constraintTop);
    }
    else if (pos.y + getBoundingRect().height > _constraintBottom)
    {
        setPosition(pos.x, _constraintBottom - getBoundingRect().height);
    }
}