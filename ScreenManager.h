#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "Unbounded_Buffer.h"
class ScreenManager
{
private:
    Unbounded_Buffer *bufferInput;
public:
    ScreenManager(Unbounded_Buffer *bufferInput);
    void display();
};
#endif