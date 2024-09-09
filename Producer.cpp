#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Bounded_Buffer.h"
#include "Producer.h"
using namespace std;

Producer::Producer(int id, int productsCount, Bounded_Buffer *buffer)
{
    this->id = id;
    this->productsCount = productsCount;
    this->buffer = buffer;
    this->types = {"SPORTS", "NEWS", "WEATHER"};
    this->types_count = {{"SPORTS", 0}, {"NEWS", 0}, {"WEATHER", 0}};
}
void Producer::produce()
{
    for (int i = 0; i < productsCount; i++)
    {
        string type = types[rand() % 3];
        string product = "Producer "+to_string(id) +" "+ type +" "+ to_string(types_count[type]);
        types_count[type]++;
        char *product_c = new char[product.size() + 1];
        strcpy(product_c, product.c_str());
        buffer->insert(product_c);
    }
    char done[]= "DONE";
    buffer->insert(done);
    return;
}