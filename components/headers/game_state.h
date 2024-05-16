#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
using namespace sf;

class GameState
{
public:
    virtual ~GameState();
    virtual void init() = 0;
    virtual void handleInput(Event *event) = 0;
    virtual void update(float elapsedTime) = 0;
    virtual void draw(RenderWindow *window) = 0;
};

#endif