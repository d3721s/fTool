#include <iostream>
#include <pthread.h>
#include <thread>
#include <chrono>

#include <FL/Fl.H>

#include "fToolUI.h"
void* startThreadUI(void* arg);
void* startThreadMain(void* arg);
int main (int argc, char ** argv)
{
    pthread_t threadUI,threadMain;

    if (pthread_create(&threadUI, NULL, startThreadUI, NULL)||
            pthread_create(&threadMain, NULL, startThreadMain, NULL))
    {
        return -1;
    }
    pthread_join(threadUI,NULL);
    pthread_join(threadMain,NULL);
    return 0;
}

void* startThreadUI(void* arg)
{
    windowMain = make_window();
    windowMain->show();
    Fl::run();
}
void* startThreadMain(void* arg)
{
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
}
