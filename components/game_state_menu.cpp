#include "./headers/game_state_menu.h"

void MenuState::init()
{
    if (!_playTexture.loadFromFile("./assets/play-btn.png") || !_exitTexture.loadFromFile("./assets/exit-btn.png"))
    {
        cout << "Error while loading assets" << endl;
        return;
    }
    _playSprite.setTexture(_playTexture);
    _exitSprite.setTexture(_exitTexture);
    _playSprite.setPosition(211, 245);
    _exitSprite.setPosition(211, 434);
}

void MenuState::handleInput(Event *event)
{
    if (event->type == Event::MouseButtonPressed)
    {
        int x = event->mouseButton.x;
        int y = event->mouseButton.y;
        if (_playSprite.getGlobalBounds().contains(x, y))
        {
            Pong::setState(Pong::Playing);
        }
        if (_exitSprite.getGlobalBounds().contains(x, y))
        {
            Pong::setState(Pong::Exiting);
        }
    }
}

void MenuState::update(float timeElapsed) {}

void MenuState::draw(RenderWindow *window)
{
    window->draw(_playSprite);
    window->draw(_exitSprite);
}