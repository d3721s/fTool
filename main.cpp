#include <iostream>
#include <pthread.h>

#include <FL/Fl.H>

#include "fToolUI.h"

int main (int argc, char ** argv)
{
    pthread_t threadUI,threadMain,threadXXX;

    if (pthread_create(&threadUI, NULL, thread_function, NULL)) {
        std::cerr << "创建线程失败：" << rc << std::endl;
        return -1;
    }

    windowMain = make_window();
    windowMain->show(argc, argv);
    return(Fl::run());
}
