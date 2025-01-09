#include <FL/Fl.H>

#include "fToolUI.h"
int main (int argc, char ** argv)
{
    windowMain = make_window();
    windowMain->show();

  return(Fl::run());
}
