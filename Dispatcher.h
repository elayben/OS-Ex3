#ifndef DISPATCHER_H
#define DISPATCHER_H
#include <vector>
#include "Bounded_Buffer.h"
#include "Unbounded_Buffer.h"
using namespace std;
class Dispatcher
{
private:
    int producers;
    vector<Bounded_Buffer *> bufferInput;
    vector<Unbounded_Buffer *> bufferOutput;
public:
    Dispatcher(int producers, vector<Bounded_Buffer *> bufferInput, vector<Unbounded_Buffer *> bufferOutput);
    void dispatch();
};
#endif // DISPATCHER_H