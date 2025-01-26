#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <FL/Fl.H>
#include "fToolUI.h"

void startThreadUI(void);
void startThreadMain(void);
int main (int argc, char ** argv)
{
    std::thread threadUI(startThreadUI);
    std::thread threadMain(startThreadMain);
    while(1)
    {
        threadUI.join();
        threadMain.join();
    }
    return 0;
}

void startThreadUI(void)
{
    windowMain = make_window();
    windowMain->show();
    Fl::run();
}

void startThreadMain(void)
{
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
}
