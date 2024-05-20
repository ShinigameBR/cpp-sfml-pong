#include "./headers/game_state_playing.h"

void PlayingState::init()
{
    Field *field = new Field();
    field->setPosition(0, 0);
    _visibleObjectManager.add("field", field);

    Player *player1 = new Player(field->getTop() + 10, field->getBottom() - 10);
    player1->setPosition(25, 384);
    _visibleObjectManager.add("player1", player1);

    Rect<float> ballConstraint = Rect(field->getLeft() + 10, field->getTop() + 10, field->getBoundingRect().width - 20, field->getBoundingRect().height - 20);
    Ball *ball = new Ball(ballConstraint);
    float centerX = field->getLeft() + field->getBoundingRect().width / 2;
    float centerY = field->getTop() + field->getBoundingRect().height / 2;
    Rect<float> ballRect = ball->getBoundingRect();
    ball->setPosition(centerX - ballRect.width / 2, centerY - ballRect.height / 2);
    _visibleObjectManager.add("ball", ball);
}

void PlayingState::handleInput(Event *event)
{
    _visibleObjectManager.handleInputAll(event);
}
void PlayingState::update(float timeElapsed)
{
    _visibleObjectManager.updateAll(timeElapsed);
}
void PlayingState::draw(RenderWindow *window)
{
    _visibleObjectManager.drawAll(window);
}