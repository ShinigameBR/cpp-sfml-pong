#include "./headers/player.h"

Player::Player(float constraintTop, float constraintBottom) : VisibleObject("./assets/player.png")
{
    _constraintTop = constraintTop;
    _constraintBottom = constraintBottom;
}

void Player::handleInput(Event *event)
{
    if (event->type == Event::KeyPressed)
    {
        if (event->key.code == Keyboard::Up)
        {
            _direction = DIRECTION_UP;
        }
        else if (event->key.code == Keyboard::Down)
        {
            _direction = DIRECTION_DOWN;
        }
    }
    else if (event->type == Event::KeyReleased)
    {
        _direction = DIRECTION_NONE;
    }
}

void Player::update(float timeElapsed)
{
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
    Vector2 pos = getPosition();
    if (pos.y < _constraintTop)
    {
        setPosition(pos.x, _constraintTop);
    }
    else if (pos.y + getBoundingRect().height > _constraintBottom)
    {
        setPosition(pos.x, _constraintBottom - getBoundingRect().height);
    }
}