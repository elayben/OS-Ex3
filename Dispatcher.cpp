#include "Bounded_Buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Dispatcher.h"
#include "Unbounded_Buffer.h"
using namespace std;

Dispatcher::Dispatcher(int producers, vector<Bounded_Buffer *> bufferInput, vector<Unbounded_Buffer *> bufferOutput)
{
    this->producers = producers;
    this->bufferInput = bufferInput;
    this->bufferOutput = bufferOutput;
}
void Dispatcher::dispatch()
{
    int bufferIndex = 0;
    int bufferCount = bufferInput.size();
    int count = 0;
    while (count < producers)
    {
        if (!bufferInput[bufferIndex]->isEmpty())
        {
            char *s = bufferInput[bufferIndex]->remove();
            int k, j;
            char type[100];
            int parsed = sscanf(s, "Producer %d %99s %d", &k, type, &j);
            if (parsed == 3)
            {
                if (strcmp(type, "SPORTS") == 0)
                {
                    bufferOutput[0]->insert(s);
                }
                else if (strcmp(type, "NEWS") == 0)
                {
                    bufferOutput[1]->insert(s);
                }
                else if (strcmp(type, "WEATHER") == 0)
                {
                    bufferOutput[2]->insert(s);
                }
            }
            if (strcmp(s, "DONE") == 0)
                count++;
        }
        bufferIndex = (bufferIndex + 1) % bufferCount;
    }
    char done[]= "DONE";
    bufferOutput[2]->insert(done);
    bufferOutput[1]->insert(done);
    bufferOutput[0]->insert(done);


    return;
}