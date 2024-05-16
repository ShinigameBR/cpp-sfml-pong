#ifndef PONG_H
#define PONG_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Pong
{
public:
    const static int SCREEN_WIDTH = 2048;
    const static int SCREEN_HEIGHT = 1536;
    static void start();
    static void gameLoop();

private:
    static RenderWindow _window;
    static Clock _clock;
};

#endif