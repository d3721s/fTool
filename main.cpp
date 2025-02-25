#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <FL/Fl.H>
#include "fToolUI.h"

extern std::unordered_map<uint8_t, std::vector<std::string>> mapProperty;

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
    std::exit(0);
}

void startThreadMain(void)
{
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
