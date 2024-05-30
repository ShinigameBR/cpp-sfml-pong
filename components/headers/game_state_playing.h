#ifndef GAME_STATE_PLAYING_H
#define GAME_STATE_PLAYING_H

#include "pong.h"
#include "game_state.h"
#include "../../entities/headers/field.h"
#include "../../entities/headers/player.h"
#include "../../entities/headers/ball.h"
#include "../../entities/headers/ai.h"

class PlayingState : public GameState
{
public:
    void init() override;
    void handleInput(Event *event) override;
    void update(float timeElapsed) override;
    void draw(RenderWindow *window) override;
    auto *drawBall(Field *field);
    void endLoopLogic() override;
};

#endif
