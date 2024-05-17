#ifndef GAME_STATE_SPLASHSCREEN_H
#define GAME_STATE_SPLASHSCREEN_H

#include "pong.h"
#include "game_state.h"

class SplashscreenState : public GameState
{
public:
    void init() override;
    void handleInput(Event *event) override;
    void update(float timeElapsed) override;
    void draw(RenderWindow *window) override;

private:
    Texture _texture;
    Sprite _sprite;
};
#endif
