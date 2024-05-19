#include "./headers/visible_object.h"

VisibleObject::VisibleObject(string textureFilename)
{
    if (!_texture.loadFromFile(textureFilename))
    {
        cout << "Error while loading asset" << endl;
        return;
    }
    _isLoaded = true;
    _sprite.setTexture(_texture);
}

VisibleObject::~VisibleObject() {}

void VisibleObject::draw(RenderWindow *window)
{
    if (!_isLoaded)
        return;
    window->draw(_sprite);
}

void VisibleObject::move(float x, float y)
{
    if (!_isLoaded)
        return;
    _sprite.move(x, y);
}

void VisibleObject::setPosition(float x, float y)
{
    if (!_isLoaded)
        return;
    _sprite.setPosition(x, y);
}

Vector2<float> VisibleObject::getPosition()
{
    return _sprite.getPosition();
}

float VisibleObject::getTop()
{
    Rect<float> boundingRect = getBoundingRect();
    return boundingRect.top;
}

float VisibleObject::getBottom()
{
    Rect<float> boundingRect = getBoundingRect();
    return boundingRect.top + boundingRect.height;
}

float VisibleObject::getLeft()
{
    Rect<float> boundingRect = getBoundingRect();
    return boundingRect.left;
}

float VisibleObject::getRight()
{
    Rect<float> boundingRect = getBoundingRect();
    return boundingRect.left + boundingRect.width;
}

Rect<float> VisibleObject::getBoundingRect()
{
    return _sprite.getGlobalBounds();
}