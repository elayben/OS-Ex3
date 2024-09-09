#include <stdio.h>
#include "Bounded_Buffer.h"
#include "Dispatcher.h"
#include "Producer.h"
#include "ScreenManager.h"
#include "CoEditor.h"
#include "Unbounded_Buffer.h"
#include <vector>
#include <thread>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    vector <Producer*> producers;
    vector <Unbounded_Buffer*> bufferOut;
    vector <Bounded_Buffer*> bufferIn;

    vector <CoEditor*> coeditors;
    vector <thread> threads;
    char* file1 = argv[1];
    int numProducers = 0;

    FILE *file = fopen(file1, "r");
    if(file == NULL)
    {
        perror("error opening file");
        return 1;
    }
    char line[256];
    int producerNumber, numberOfProducts, queueSize;
    while(fgets(line, sizeof(line), file)!=NULL)
    {
        // parse producer line
        if (sscanf(line, "PRODUCER %d", &producerNumber) == 1) {

            if (fgets(line, sizeof(line), file) != NULL && sscanf(line, "%d", &numberOfProducts) == 1) {
            }

            if (fgets(line, sizeof(line), file) != NULL && sscanf(line, "queue size = %d", &queueSize) == 1) {
                Bounded_Buffer *b = new Bounded_Buffer(queueSize);
                bufferIn.push_back(b);
                Producer *producer = new Producer(producerNumber, numberOfProducts, b);
                producers.push_back(producer);
                numProducers++;
            }
        }
    }
    fclose(file);
    Unbounded_Buffer *news = new Unbounded_Buffer("news");
    Unbounded_Buffer *sports = new Unbounded_Buffer("sports");
    Unbounded_Buffer *weather = new Unbounded_Buffer("weather");
    bufferOut.push_back(news);
    bufferOut.push_back(sports);
    bufferOut.push_back(weather);

    Unbounded_Buffer *manager = new Unbounded_Buffer("manager");

    ScreenManager *sm = new ScreenManager(manager);

    CoEditor *sports_editor = new CoEditor(sports,manager);
    CoEditor *news_editor = new CoEditor(news,manager);
    CoEditor *weather_editor = new CoEditor(weather,manager);
    coeditors.push_back(sports_editor);
    coeditors.push_back(news_editor);
    coeditors.push_back(weather_editor);

    Dispatcher *d = new Dispatcher(numProducers,bufferIn,bufferOut);


    for(Producer *producer : producers)
    {
        threads.push_back(thread(&Producer::produce, producer));
    }

    threads.push_back(thread(&Dispatcher::dispatch, d));

    for(CoEditor *c : coeditors)
    {
        threads.push_back(thread(&CoEditor::edit, c));
    }

    threads.push_back(thread(&ScreenManager::display, sm));

    // join all the thrreds
    for(thread &t : threads)
    {
        t.join();
    }
    return 0;
}