#include "./headers/game_state_splashscreen.h"

void SplashscreenState::init()
{
    if (!_texture.loadFromFile("./assets/pong-logo.png"))
    {
        cout << "Error while loading assets " << endl;
        return;
    }
    _sprite.setTexture(_texture);
}

void SplashscreenState::handleInput(Event *event)
{
    if (event->type == Event::KeyPressed || event->type == Event::MouseButtonPressed)
    {
        Pong::setState(Pong::Menu);
    }
}

void SplashscreenState::update(float timeElapsed) {}

void SplashscreenState::draw(RenderWindow *window)
{
    window->draw(_sprite);
}