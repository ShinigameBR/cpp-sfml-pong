#include "./headers/game_state.h"

GameState::~GameState() {}

VisibleObjectManager *GameState::getObjectManager() { return &_visibleObjectManager; }