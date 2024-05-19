#ifndef VISIBLE_OBJECT_H
#define VISIBLE_OBJECT_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class VisibleObject
{
public:
    VisibleObject(string textureFilename);
    virtual ~VisibleObject();
    virtual void handleInput(Event *event) {};
    virtual void update(float timeElapsed) = 0;
    virtual void draw(RenderWindow *window);
    virtual void collideWith(VisibleObject *target) {};
    virtual void move(float x, float y);
    virtual void setPosition(float x, float y);
    virtual Vector2<float> getPosition();
    virtual float getTop();
    virtual float getBottom();
    virtual float getLeft();
    virtual float getRight();
    virtual Rect<float> getBoundingRect();

private:
    Texture _texture;
    Sprite _sprite;
    bool _isLoaded;
};
#endif