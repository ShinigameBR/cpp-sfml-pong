#ifndef GAME_STATE_PLAYING_H
#define GAME_STATE_PLAYING_H

#include "game_state.h"

class PlayingState : public GameState
{
public:
    void init() override;
    void handleInput(Event *event) override;
    void update(float timeElapsed) override;
    void draw(RenderWindow *window) override;
};
#endif
