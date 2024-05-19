#include "./headers/game_state_playing.h"

void PlayingState::init()
{
    Field *field = new Field();
    field->setPosition(0, 0);
    _visibleObjectManager.add("field", field);
    Player *player1 = new Player(field->getTop() + 10, field->getBottom() - 10);
    player1->setPosition(25, 384);
    _visibleObjectManager.add("player1", player1);
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