#ifndef GAME_STATE_PLAYING_H
#define GAME_STATE_PLAYING_H

#include "pong.h"
#include "game_state.h"

class PlayingState : public GameState
{
public:
    void init() override;
    void handleInput(Event *event) override;
    void update(float timeElapsed) override;
    void draw(RenderWindow *window) override;

private:
    Texture _player1Texture;
    Sprite _player1Sprite;
    float _playerSpeed = 800.0f;
    enum Direction
    {
        DIRECTION_NONE,
        DIRECTION_UP,
        DIRECTION_DOWN
    };
    Direction _playerDirection = DIRECTION_NONE;
};
#endif
