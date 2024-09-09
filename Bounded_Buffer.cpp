#include <queue>
#include <string>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <cstring>
#include <semaphore.h>
#include "Bounded_Buffer.h"
using namespace std;

Bounded_Buffer::Bounded_Buffer(int length) : length(length), tempBuffer(queue<string>()) {}
void Bounded_Buffer::insert(char *s)
{
    std::unique_lock<std::mutex> lock(mutex);
    not_full.wait(lock, [this]() { return tempBuffer.size() < length; });
    tempBuffer.push(s);
    not_empty.notify_one();
}
char *Bounded_Buffer::remove()
{
    std::unique_lock<std::mutex> lock(mutex);
    not_empty.wait(lock, [this]() { return !tempBuffer.empty(); });
    std::string s = tempBuffer.front();
    tempBuffer.pop();
    not_full.notify_one();
    char *res = new char[s.length() + 1];
    std::strcpy(res, s.c_str());


    return res;
}
bool Bounded_Buffer:: isEmpty(){
    unique_lock<std::mutex> lock(mutex);
    return tempBuffer.empty();
}