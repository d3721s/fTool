#include <iostream>
#include <pthread.h>
#include <thread>
#include <chrono>
#include <windows.h>
#include <FL/Fl.H>

#include "log.h"
#include "ini.h"

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
    log_set_quiet(true);
    FILE* logFile = fopen(".fToolLog.txt","a");
    log_add_fp(logFile,LOG_INFO);
    log_info("program start");
#ifdef __WIN32
    SetFileAttributes(".fToolLog.txt", FILE_ATTRIBUTE_HIDDEN);
#endif // __WIN32
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
}
