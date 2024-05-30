#include "./headers/game_state_playing.h"

auto *PlayingState::drawBall(Field *field)
{
    Rect<float> ballConstraint = Rect(field->getLeft() + 10, field->getTop() + 10, field->getBoundingRect().width - 20, field->getBoundingRect().height - 20);
    Ball *ball = new Ball(ballConstraint);
    float centerX = field->getLeft() + field->getBoundingRect().width / 2;
    float centerY = field->getTop() + field->getBoundingRect().height / 2;
    Rect<float> ballRect = ball->getBoundingRect();
    ball->setPosition(centerX - ballRect.width / 2, centerY - ballRect.height / 2);
    return ball;
}

void PlayingState::init()
{
    Field *field = new Field();
    field->setPosition(0, 0);
    _visibleObjectManager.add("field", field);

    Player *player = new Player(field->getTop() + 10, field->getBottom() - 10);
    player->setPosition(25, 384);
    _visibleObjectManager.add("player", player);

    Ai *ai = new Ai(field->getTop() + 10, field->getBottom() - 10);
    ai->setPosition(979, 384);
    _visibleObjectManager.add("ai", ai);

    _visibleObjectManager.add("ball", drawBall(field));
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

void PlayingState::endLoopLogic()
{
    Ball *ball = dynamic_cast<Ball *>(_visibleObjectManager.get("ball"));
    if (ball->isOut)
    {
        _visibleObjectManager.remove("ball");
        Field *field = dynamic_cast<Field *>(_visibleObjectManager.get("field"));
        _visibleObjectManager.add("ball", drawBall(field));
    }
}