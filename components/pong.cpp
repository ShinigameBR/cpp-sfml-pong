#include "./headers/pong.h"

RenderWindow Pong::_window;
Clock Pong::_clock;

void Pong::start()
{
    if (_window.isOpen())
        return;
    // Init the window
    _window.create(VideoMode(Pong::SCREEN_WIDTH, Pong::SCREEN_HEIGHT, 32), "Pong");
    _window.setFramerateLimit(60);
    gameLoop();
}

void Pong::gameLoop()
{
    while (_window.isOpen())
    {
        // Get the time elapsed since the last loop execution
        float timeElapsed = _clock.restart().asSeconds();
        // Reset our window content
        _window.clear(Color(255, 255, 255));
        // Handle input
        Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _window.close();
            }
            // Here we will handle other inputs type
        }
        // Update our entities
        // Draw our new entities
        _window.display();
    }
}