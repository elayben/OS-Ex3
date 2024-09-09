#include "CoEditor.h"
#include "Unbounded_Buffer.h"
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;
CoEditor::CoEditor(Unbounded_Buffer *bufferInput, Unbounded_Buffer *bufferOutput)
{
    this->bufferInput = bufferInput;
    this->bufferOutput = bufferOutput;
}
void CoEditor::edit()
{
    while (true)
    {
        if (!bufferInput->isEmpty())
        {
            char *s = bufferInput->remove();
            if (strcmp(s, "DONE") != 0)
            {
                usleep(100000);
                bufferOutput->insert(s);
            }
            else
            {

                bufferOutput->insert(s);
                return;
            }
        }
    }
    return;
}