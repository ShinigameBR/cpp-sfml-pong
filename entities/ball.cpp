#include "./headers/ball.h"

Ball::Ball(Rect<float> constraints) : VisibleObject("./assets/ball.png")
{
    _speed = 500.0f;
    _angle = rand() % 2 == 0 ? 0 : 180;
    _constraints = constraints;
}

void Ball::update(float timeElapsed)
{
    float velocity = _speed * timeElapsed;
    float angleInRadian = _angle * M_PI / 180.0f;
    float velocityX = velocity * cos(angleInRadian) - 0 * sin(angleInRadian);
    float velocityY = 0 * cos(angleInRadian) + velocity * sin(angleInRadian);

    // Handle bounce with the top & bottom walls
    if (getTop() + velocityY <= _constraints.top || getBottom() + velocityY >= _constraints.top + _constraints.height)
    {
        _angle = 360 - _angle;
        velocityY *= -1;
    }
    // Temporarily handle bounce with the side walls
    if (getLeft() + velocityX <= _constraints.left || getRight() + velocityX >= _constraints.left + _constraints.width)
    {
        _angle = (180 - _angle) % 360;
        velocityX *= -1;
    }

    move(velocityX, velocityY);
}