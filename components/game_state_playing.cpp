#include "./headers/game_state_playing.h"

void PlayingState::init()
{
    if (!_player1Texture.loadFromFile("./assets/player.png"))
    {
        cout << "Error while loading assets" << endl;
        return;
    }
    _player1Sprite.setTexture(_player1Texture);
    _player1Sprite.setPosition(25, 359);
}
void PlayingState::handleInput(Event *event)
{
    if (event->type == Event::KeyReleased)
    {
        _playerDirection = DIRECTION_NONE;
    }
    else if (event->type == Event::KeyPressed)
    {
        if (event->key.code == Keyboard::Up)
        {
            _playerDirection = DIRECTION_UP;
        }
        else if (event->key.code == Keyboard::Down)
        {
            _playerDirection = DIRECTION_DOWN;
        }
    }
}
void PlayingState::update(float timeElapsed)
{
    float velocity = 0.0f;
    if (_playerDirection == DIRECTION_UP)
    {
        velocity = _playerSpeed * -1;
    }
    else if (_playerDirection == DIRECTION_DOWN)
    {
        velocity = _playerSpeed;
    }
    _player1Sprite.move(0, velocity * timeElapsed);
}
void PlayingState::draw(RenderWindow *window)
{
    window->draw(_player1Sprite);
}