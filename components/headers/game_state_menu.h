#ifndef GAME_STATE_MENU_H
#define GAME_STATE_MENU_H

#include "pong.h"
#include "game_state.h"

class MenuState : public GameState
{
public:
    void init() override;
    void handleInput(Event *event) override;
    void update(float timeElapsed) override;
    void draw(RenderWindow *window) override;

private:
    Texture _playTexture;
    Sprite _playSprite;
    Texture _exitTexture;
    Sprite _exitSprite;
};

#endif
