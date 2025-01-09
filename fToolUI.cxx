// generated by Fast Light User Interface Designer (fluid) version 1.0401

#include "fToolUI.h"

void callbackMenuitemFileopen(Fl_Menu_* w, void*) {
  Fl_Native_File_Chooser fnfc;
      fnfc.title("选择配置文件");
      fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
      fnfc.options(Fl_Native_File_Chooser::SAVEAS_CONFIRM|Fl_Native_File_Chooser::USE_FILTER_EXT|Fl_Native_File_Chooser::NEW_FOLDER );
      fnfc.filter("fTool Data File\t*.ftd\n");
      switch ( fnfc.show() )
      {
      case -1:
          printf("ERROR: %s\n", fnfc.errmsg());
          break;
      case  1:
          printf("CANCEL\n");
          break;
      default:
          printf("PICKED: %s\n", fnfc.filename());
          break;
      }
}

static void callbackMenuitemMinimize(Fl_Menu_* w, void*) {
  Fl_Window* wd = w->window();
  wd->iconize();
}

static void callbackMenuitemClose(Fl_Menu_* w, void*) {
  Fl_Window* wd = w->window();
  wd->hide();
}

Fl_Double_Window *windowMain=(Fl_Double_Window *)0;

Fl_Menu_Bar *barMain=(Fl_Menu_Bar *)0;

Fl_Menu_Item menu_barMain[] = {
 {"@fileopen", 0,  (Fl_Callback*)callbackMenuitemFileopen, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"@filesave", 0,  0, 0, 128, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"@undo", FL_CONTROL|'z',  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"@redo", FL_CONTROL|'y',  0, 0, 128, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"                                                             fTool           "
"                                                  ", 0,  0, 0, 129, (uchar)FL_NORMAL_LABEL, 1, 14, 0},
 {"@2>", 0,  (Fl_Callback*)callbackMenuitemMinimize, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"@1+", 0,  (Fl_Callback*)callbackMenuitemClose, 0, 128, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Group *groupConnect=(Fl_Group *)0;

Fl_Button *buttonConnect=(Fl_Button *)0;

Fl_Button *buttonRead=(Fl_Button *)0;

Fl_Button *buttonCopy=(Fl_Button *)0;

Fl_Button *buttonWrite=(Fl_Button *)0;

Fl_Group *groupRead=(Fl_Group *)0;

Fl_Group *groupWrite=(Fl_Group *)0;

Fl_Double_Window* make_window() {
  { windowMain = new Fl_Double_Window(720, 480, "fTool");
    windowMain->color(FL_LIGHT3);
    windowMain->labelcolor(FL_DARK2);
    { barMain = new Fl_Menu_Bar(0, 0, 720, 30);
      barMain->box(FL_PLASTIC_THIN_UP_BOX);
      barMain->color(FL_LIGHT3);
      barMain->labeltype(FL_NO_LABEL);
      barMain->menu(menu_barMain);
    } // Fl_Menu_Bar* barMain
    { groupConnect = new Fl_Group(10, 40, 200, 250);
      groupConnect->box(FL_PLASTIC_THIN_UP_BOX);
      groupConnect->color(FL_LIGHT3);
      groupConnect->labeltype(FL_NO_LABEL);
      { buttonConnect = new Fl_Button(140, 250, 60, 30, "连接");
        buttonConnect->type(1);
        buttonConnect->box(FL_PLASTIC_THIN_UP_BOX);
        buttonConnect->down_box(FL_PLASTIC_THIN_DOWN_BOX);
        buttonConnect->color(FL_LIGHT3);
      } // Fl_Button* buttonConnect
      groupConnect->end();
    } // Fl_Group* groupConnect
    { buttonRead = new Fl_Button(20, 300, 180, 50, "@refresh    一键读取");
      buttonRead->box(FL_PLASTIC_THIN_UP_BOX);
      buttonRead->color(FL_LIGHT3);
    } // Fl_Button* buttonRead
    { buttonCopy = new Fl_Button(20, 358, 180, 50, "@filenew    复制参数");
      buttonCopy->box(FL_PLASTIC_THIN_UP_BOX);
      buttonCopy->color(FL_LIGHT3);
    } // Fl_Button* buttonCopy
    { buttonWrite = new Fl_Button(20, 416, 180, 50, "@2->|    一键写入");
      buttonWrite->box(FL_PLASTIC_THIN_UP_BOX);
      buttonWrite->color(FL_LIGHT3);
    } // Fl_Button* buttonWrite
    { groupRead = new Fl_Group(220, 40, 490, 210);
      groupRead->box(FL_PLASTIC_THIN_UP_BOX);
      groupRead->color(FL_LIGHT3);
      groupRead->end();
    } // Fl_Group* groupRead
    { groupWrite = new Fl_Group(220, 260, 490, 210);
      groupWrite->box(FL_PLASTIC_THIN_UP_BOX);
      groupWrite->color(FL_LIGHT3);
      groupWrite->end();
    } // Fl_Group* groupWrite
    windowMain->size_range(720, 480, 720, 480);
    windowMain->end();
  } // Fl_Double_Window* windowMain
  return windowMain;
}