#ifndef PONG_H
#define PONG_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "game_state.h"
#include "game_state_splashscreen.h"
#include "game_state_menu.h"
#include "game_state_playing.h"

using namespace sf;
using namespace std;

class Pong
{
public:
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;
    static void start();
    static void gameLoop();
    enum State
    {
        Uninitialized,
        Splashscreen,
        Menu,
        Playing,
        Exiting
    };
    static void setState(State s);

private:
    static State _state;
    static map<State, GameState *> _stateInstances;
    static RenderWindow _window;
    static Clock _clock;
};

#endif