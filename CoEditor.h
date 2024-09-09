#include <iostream>
#include "Unbounded_Buffer.h"
using namespace std;
class CoEditor{
private:
    Unbounded_Buffer* bufferInput;
    Unbounded_Buffer* bufferOutput;
public:
    CoEditor(Unbounded_Buffer *bufferInput, Unbounded_Buffer *bufferOutput);
    void edit();
};