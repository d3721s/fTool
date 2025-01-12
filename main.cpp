#include <iostream>
#include <pthread.h>
#include <thread>
#include <chrono>
#include <windows.h>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include <FL/Fl.H>

#include "fToolUI.h"
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

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
    #ifdef log
    logging::add_file_log(".fTool.log");
//    logging::core::get()->set_filter
//    (
//        logging::trivial::severity >= logging::trivial::info
//    );
//    logging::add_common_attributes();
//
//    using namespace logging::trivial;
//    src::severity_logger< severity_level > lg;
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
#ifdef __WIN32
    SetFileAttributes(".fToolLog.log", FILE_ATTRIBUTE_HIDDEN);
#endif // __WIN32
#endif // log
    while(1)
    {
//        std::cout <<"qwe"<<std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(4));
//        logging::core::get()->flush();
    }
}
