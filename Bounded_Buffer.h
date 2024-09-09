#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <semaphore.h>
using namespace std;
class Bounded_Buffer
{
private:
    int length;
    queue<string> tempBuffer;
    condition_variable not_empty;
    condition_variable not_full;
    std::mutex mutex;

public:
    Bounded_Buffer(int size);
    void insert(char *s);
    char *remove();
    bool isEmpty();
};
#endif // BOUNDED_BUFFER_H