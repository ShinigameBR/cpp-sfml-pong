#include "./headers/visible_object_manager.h"

VisibleObjectManager::~VisibleObjectManager()
{
    auto itr = _objects.begin();
    while (itr != _objects.end())
    {
        delete itr->second;
        itr++;
    }
}

void VisibleObjectManager::add(string name, VisibleObject *object)
{
    _objects.insert(pair<string, VisibleObject *>(name, object));
}

void VisibleObjectManager::remove(string name)
{
    auto results = _objects.find(name);
    if (results != _objects.end())
    {
        delete results->second;
        _objects.erase(results);
    }
}

VisibleObject *VisibleObjectManager::get(string name)
{
    auto results = _objects.find(name);
    if (results == _objects.end())
        return NULL;
    return results->second;
}

void VisibleObjectManager::handleInputAll(Event *event)
{
    auto itr = _objects.begin();
    while (itr != _objects.end())
    {
        itr->second->handleInput(event);
        itr++;
    }
}

void VisibleObjectManager::updateAll(float timeElapsed)
{
    auto itr = _objects.begin();
    while (itr != _objects.end())
    {
        itr->second->update(timeElapsed);
        itr++;
    }

    // Detect collision.
    auto originItr = _objects.begin();
    while (originItr != _objects.end())
    {
        Rect<float> originBound = originItr->second->getBoundingRect();
        auto targetItr = _objects.begin();
        while (targetItr != _objects.end())
        {
            if (targetItr == originItr)
            {
                targetItr++;
                continue;
            }

            Rect<float> targetBound = targetItr->second->getBoundingRect();
            if (originBound.intersects(targetBound))
            {
                originItr->second->collideWith(targetItr->second);
            }
            targetItr++;
        }
        originItr++;
    }
}

void VisibleObjectManager::drawAll(RenderWindow *window)
{
    auto itr = _objects.begin();
    while (itr != _objects.end())
    {
        itr->second->draw(window);
        itr++;
    }
}