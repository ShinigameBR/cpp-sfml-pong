#include "./headers/pong.h"

RenderWindow Pong::_window;
Clock Pong::_clock;
Pong::State Pong::_state = Uninitialized;
map<Pong::State, GameState *> Pong::_stateInstances;

void Pong::start()
{
    if (_state != Uninitialized)
        return;
    _window.create(VideoMode(Pong::SCREEN_WIDTH, Pong::SCREEN_HEIGHT, 32), "Pong");
    _window.setFramerateLimit(60);
    _stateInstances[Splashscreen] = new SplashscreenState();
    _stateInstances[Splashscreen]->init();
    _stateInstances[Menu] = new MenuState();
    _stateInstances[Menu]->init();
    _stateInstances[Playing] = new PlayingState();
    _stateInstances[Playing]->init();
    _state = Splashscreen;
    gameLoop();
    auto itr = _stateInstances.begin();
    while (itr != _stateInstances.end())
    {
        delete itr->second;
        itr++;
    }
    _window.close();
}

void Pong::gameLoop()
{
    while (_window.isOpen())
    {
        float timeElapsed = _clock.restart().asSeconds();
        _window.clear(Color(255, 255, 255));

        // Because we don't want to change our state during a frame
        GameState *currentState = _stateInstances[_state];
        // Handle input
        Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _state = Exiting;
            }
            currentState->handleInput(&event);
        }
        // Update our entities
        currentState->update(timeElapsed);
        // Draw our new entities
        currentState->draw(&_window);
        _window.display();
    }
}

void Pong::setState(Pong::State s) { _state = s; }
