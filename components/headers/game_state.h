#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "visible_object_manager.h"
using namespace sf;

class GameState
{
public:
    virtual ~GameState();
    virtual void init() = 0;
    virtual void handleInput(Event *event) = 0;
    virtual void update(float elapsedTime) = 0;
    virtual void draw(RenderWindow *window) = 0;
    virtual void endLoopLogic() {};
    VisibleObjectManager *getObjectManager();

protected:
    VisibleObjectManager _visibleObjectManager;
};

#endif