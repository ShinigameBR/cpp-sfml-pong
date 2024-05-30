#ifndef VISIBLE_OBJECT_MANAGER_H
#define VISIBLE_OBJECT_MANAGER_H

#include "visible_object.h"

class VisibleObjectManager
{
public:
    ~VisibleObjectManager();
    void add(string name, VisibleObject *object);
    void remove(string name);
    VisibleObject *get(string name);
    void handleInputAll(Event *event);
    void updateAll(float timeElapsed);
    void drawAll(RenderWindow *window);

private:
    map<string, VisibleObject *> _objects;
};

#endif