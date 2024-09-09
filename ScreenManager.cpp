#include "Unbounded_Buffer.h"
#include <iostream>
#include "ScreenManager.h"
using namespace std;
ScreenManager::ScreenManager(Unbounded_Buffer *bufferInput)
{
    this->bufferInput = bufferInput;
}
void ScreenManager::display()
{
    int cnt = 0;
    while (cnt < 3)
    {
        if (!bufferInput->isEmpty())
        {
            char *s = bufferInput->remove();
            if(strcmp(s, "DONE") != 0)
                cout << s << endl;

            if (strcmp(s, "DONE") == 0)
            {
                cnt++;
            }
        }
    }
    cout << "DONE" << endl;
}