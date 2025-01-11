// generated by Fast Light User Interface Designer (fluid) version 1.0401

#ifndef fToolUI_h
#define fToolUI_h
#include <FL/Fl.H>
#include <FL/Fl_Native_File_Chooser.H>
#include "log.h"
#include "ini.h"
void pushFTD(mINI::INIStructure* fileIni);
void pullFTD(mINI::INIStructure* fileIni);
#include <FL/Fl_Double_Window.H>
extern Fl_Double_Window *windowMain;
#include <FL/Fl_Menu_Bar.H>
extern Fl_Menu_Bar *barMain;
#include <cstdlib>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Group.H>
extern Fl_Group *groupConnectSocket;
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
extern Fl_Group *groupConnectSerial;
#include <FL/Fl_Input_Choice.H>
extern Fl_Button *buttonRead;
extern Fl_Button *buttonCopy;
extern Fl_Button *buttonWrite;
extern Fl_Button *buttonCustom;
extern Fl_Group *groupRead;
extern Fl_Group *groupWrite;
Fl_Double_Window* make_window();
extern Fl_Menu_Item menu_barMain[];
#define menuitemFileopen (menu_barMain+0)
#define menuitemFilesave (menu_barMain+1)
#define menuitemTitle (menu_barMain+2)
#define menuitemMinimize (menu_barMain+3)
#define menuitemClose (menu_barMain+4)
extern Fl_Menu_Item menu_3circle[];
#endif
