#ifndef PRODUCER_H
#define PRODUCER_H
#include <vector>
#include <map>
#include <string>
#include "Bounded_Buffer.h"
using namespace std;
class Producer
{
private:
    int id;
    int productsCount;
    map<string, int> types_count;
    vector<string> types;
    Bounded_Buffer* buffer;

public:
    Producer(int id, int productsCount, Bounded_Buffer* buffer);
    void produce();
};
#endif // PRODUCER_H