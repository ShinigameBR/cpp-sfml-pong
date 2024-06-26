#include "./headers/ball.h"

Ball::Ball(Rect<float> constraints) : VisibleObject("./assets/ball.png")
{
    _speed = 500.0f;
    _angle = rand() % 2 == 0 ? 0 : 180;
    _constraints = constraints;
}

void Ball::update(float timeElapsed)
{
    if (isOut)
        return;

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

    // Handle loss condition on the left wall
    if (getLeft() + velocityX <= _constraints.left || getRight() + velocityX >= _constraints.left + _constraints.width)
    {
        isOut = true;
    }

    move(velocityX, velocityY);
}

void Ball::collideWith(VisibleObject *target)
{
    if (isOut)
        return;

    if (!dynamic_cast<Player *>(target) && !dynamic_cast<Ai *>(target))
        return;
    float targetCenterY = (target->getTop() + target->getBottom()) / 2;
    float ballCenterY = (getTop() + getBottom()) / 2;
    float distDiff = ballCenterY - targetCenterY;
    float maxDiff = target->getBoundingRect().height;
    float normalizedDiff = distDiff / maxDiff;
    if (target->getPosition().x < Pong::SCREEN_WIDTH / 2)
    {
        _angle = (int)(normalizedDiff * 90); // Between -45 and 45 degree
    }
    else
    {
        _angle = 180 - (int)(normalizedDiff * 90);
    }

    _speed += 100;
    if (_speed > _maxSpeed)
        _speed = _maxSpeed;
}