// generated by Fast Light User Interface Designer (fluid) version 1.0401

#include "fToolUI.h"
#include "map.txt"

void pushFTD(mINI::INIStructure* fileIni)
{
    printf("Hello, World!\n");
}

void pullFTD(mINI::INIStructure* fileIni)
{
    printf("Hello, World!\n");
}

void WidgetTable::draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H)
{
    switch ( context )
    {
    case CONTEXT_STARTPAGE:
        break;
    case CONTEXT_RC_RESIZE:
    {
        int X, Y, W, H;
        int index = 0;
        for ( int r = 0; r<rows(); r++ )
        {
            for ( int c = 0; c<cols(); c++ )
            {
                if ( index >= children() ) break;
                find_cell(CONTEXT_TABLE, r, c, X, Y, W, H);
                child(index++)->resize(X,Y,W,H);
            }
        }
        init_sizes();
        return;
    }
    case CONTEXT_ROW_HEADER:
        fl_push_clip(X, Y, W, H);
        {
            fl_color(FL_LIGHT2);
            fl_rectf(X,Y,W,H);
            static char s[40];
            if (mapProperty.find(R) != mapProperty.end())
            {
                std::sprintf(s, "%s", mapProperty[R][0].c_str());
            }
            else
            {
                sprintf(s, "Row %d", R);
            }
            fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
            fl_color(FL_BLACK);
            fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
            fl_color(FL_LIGHT3);
            fl_rect(X,Y,W,H);
        }
        fl_pop_clip();
        return;
    case CONTEXT_COL_HEADER:
        fl_push_clip(X, Y, W, H);
        {
            fl_color(FL_LIGHT2);
            fl_rectf(X,Y,W,H);
            static char s[40];
            switch(C)
            {
            case 0:
                sprintf(s, "名称");
                break;
            case 1:
                sprintf(s, "当前值");
                break;
            case 2:
                sprintf(s, "待写入");
                break;
            case 3:
                sprintf(s, "操作");
                break;
            default:
                break;
            }
            fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, col_header_color());
            fl_color(FL_BLACK);
            fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
            fl_color(FL_LIGHT3);
            fl_rect(X,Y,W,H);
        }
        fl_pop_clip();
        return;
    case CONTEXT_CELL:
        return;
    default:
        return;
    }
}

WidgetTable::WidgetTable(int x, int y, int w, int h, const char *l) : Fl_Table(x,y,w,h,l)
{
    col_header(1);
    col_header_height(25);
    row_header(1);
    clear();
    rows(186);
    cols(4);
    col_width(0,200);
    col_width(1,80);
    col_width(2,80);
    col_width(3,65);
    begin();
    {
        for ( int r = 0; r<186; r++ )
        {
            for ( int c = 0; c<4; c++ )
            {
                int X,Y,W,H;
                find_cell(CONTEXT_TABLE, r, c, X, Y, W, H);

                char s[40];
                if ( c == 0 )
                {
                    Fl_Text_Display *disp = new Fl_Text_Display(X,Y,W,H);
                    Fl_Text_Buffer *tbuff = new Fl_Text_Buffer();
                    disp->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
                    disp->box(FL_BORDER_BOX);
                    disp->color(FL_LIGHT1,FL_BLACK);
                    disp->buffer(tbuff);
                    tbuff->text(mapProperty[r][1].c_str());
                }
                else if(c == 1)
                {
                    Fl_Output* o = new Fl_Output(X,Y,W,H);
                    o->box(FL_BORDER_BOX);
                    o->labeltype(FL_NO_LABEL);
                    o->value("");
///output array to be done
                }
                else if (c == 2)
                {
///output array to be done
                    Fl_Input *in = new Fl_Input(X,Y,W,H);
                    in->box(FL_BORDER_BOX);
                    in->labeltype(FL_NO_LABEL);

                    //                    in->value(s);
                }
                else
                {
 ///output array to be done
                   Fl_Button *butt = new Fl_Button(X,Y,W,H);
                    butt->copy_label("写入");
                    butt->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
                    butt->box(FL_THIN_UP_BOX);

                    //                    butt->callback(button_cb, (void*)0);
                }
            }
        }
    }
    end();
}

WidgetTable::~WidgetTable()
{
    printf("Hello, World!\n");
}
// 分隔符
// 分隔符
// 分隔符
// 分隔符
// 分隔符
// 分隔符
// 分隔符
// 分隔符

Fl_Double_Window *windowMain=(Fl_Double_Window *)0;

Fl_Menu_Bar *barMain=(Fl_Menu_Bar *)0;

static void cb_menuitemFileopen(Fl_Menu_*, void*)
{
    Fl_Native_File_Chooser fnfc;
    fnfc.title("选择数据文件");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
    fnfc.options(Fl_Native_File_Chooser::USE_FILTER_EXT);
    fnfc.filter("fTool Data File\t*.ftd\n");
    if ((fnfc.show() != 0) ||(!fnfc.filename())) return;
    mINI::INIFile fileFTD(fnfc.filename());
    mINI::INIStructure FTD;
    fileFTD.read(FTD);
    pullFTD(&FTD);
}

static void cb_menuitemFilesave(Fl_Menu_*, void*)
{
    Fl_Native_File_Chooser fnfc;
    fnfc.title("保存数据文件");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
    fnfc.options(Fl_Native_File_Chooser::SAVEAS_CONFIRM | Fl_Native_File_Chooser::USE_FILTER_EXT);
    fnfc.filter("fTool Data File\t*.ftd\n");
    fnfc.preset_file("preset.ftd");
    if ((fnfc.show() != 0) ||(!fnfc.filename())) return;
    mINI::INIFile fileFTD(fnfc.filename());
    mINI::INIStructure FTD;
    pushFTD(&FTD);
    fileFTD.generate(FTD);
}

static void cb_menuitemMinimize(Fl_Menu_*, void*)
{
    Fl::belowmouse()->parent()->as_window()->iconize();
}

static void cb_menuitemClose(Fl_Menu_*, void*)
{
    std::exit(0);
}

Fl_Menu_Item menu_barMain[] =
{
    {"@fileopen", FL_CONTROL|'o',  (Fl_Callback*)cb_menuitemFileopen, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
    {"@filesave", FL_CONTROL|'s',  (Fl_Callback*)cb_menuitemFilesave, 0, 128, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
    {
        "                                                                     fTool   "
        "                                                                 ", 0,  0, 0, 129, (uchar)FL_NORMAL_LABEL, 1, 14, 0
    },
    {"@2>", 0,  (Fl_Callback*)cb_menuitemMinimize, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
    {"@1+", 0,  (Fl_Callback*)cb_menuitemClose, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
    {0,0,0,0,0,0,0,0,0}
};

Fl_Wizard *wizardConnect=(Fl_Wizard *)0;

Fl_Group *groupConnectSocket=(Fl_Group *)0;

Fl_Button *buttonToSerial=(Fl_Button *)0;

static void cb_buttonToSerial(Fl_Button*, void*)
{
    wizardConnect->next();
}

Fl_Group *groupConnectSerial=(Fl_Group *)0;

Fl_Menu_Item menu_3circle[] =
{
    {"9600", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
    {"115200", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
    {"460800", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
    {0,0,0,0,0,0,0,0,0}
};

Fl_Button *buttonToSocket=(Fl_Button *)0;

static void cb_buttonToSocket(Fl_Button*, void*)
{
    wizardConnect->prev();
}

Fl_Button *buttonRead=(Fl_Button *)0;

static void cb_buttonRead(Fl_Button*, void*)
{
    fl_message("连接后自动读取参数，无需手动读取");
}

Fl_Button *buttonCopy=(Fl_Button *)0;

Fl_Button *buttonWrite=(Fl_Button *)0;

Fl_Button *buttonCustom=(Fl_Button *)0;

WidgetTable *iniTable=(WidgetTable *)0;

Fl_Double_Window* make_window()
{
    {
        windowMain = new Fl_Double_Window(720, 480, "fTool");
        windowMain->color(FL_LIGHT2);
        windowMain->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
        {
            barMain = new Fl_Menu_Bar(0, 0, 720, 30);
            barMain->box(FL_THIN_UP_BOX);
            barMain->color(FL_LIGHT2);
            barMain->menu(menu_barMain);
        } // Fl_Menu_Bar* barMain
        {
            wizardConnect = new Fl_Wizard(15, 45, 195, 160);
            wizardConnect->color(FL_GRAY0);
            {
                groupConnectSocket = new Fl_Group(15, 45, 195, 160);
                groupConnectSocket->box(FL_THIN_UP_FRAME);
                groupConnectSocket->color(FL_LIGHT2);
                groupConnectSocket->labeltype(FL_NO_LABEL);
                {
                    Fl_Input* o = new Fl_Input(25, 70, 175, 30, "@-3circle  远程主机地址");
                    o->labelfont(1);
                    o->labelsize(15);
                    o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                } // Fl_Input* o
                {
                    Fl_Input* o = new Fl_Input(25, 125, 175, 30, "@-3circle  远程主机端口");
                    o->labelfont(1);
                    o->labelsize(15);
                    o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                } // Fl_Input* o
                {
                    buttonToSerial = new Fl_Button(25, 165, 85, 30, "切换到串口");
                    buttonToSerial->color(FL_LIGHT2);
                    buttonToSerial->labelfont(1);
                    buttonToSerial->callback((Fl_Callback*)cb_buttonToSerial);
                } // Fl_Button* buttonToSerial
                {
                    Fl_Light_Button* o = new Fl_Light_Button(120, 165, 80, 30, "连接");
                    o->box(FL_THIN_UP_BOX);
                    o->color(FL_LIGHT2);
                    o->selection_color(FL_GREEN);
                    o->labelfont(1);
                    o->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
                } // Fl_Light_Button* o
                groupConnectSocket->end();
            } // Fl_Group* groupConnectSocket
            {
                groupConnectSerial = new Fl_Group(15, 45, 195, 160);
                groupConnectSerial->box(FL_THIN_UP_FRAME);
                groupConnectSerial->color(FL_LIGHT2);
                groupConnectSerial->labeltype(FL_NO_LABEL);
                groupConnectSerial->hide();
                {
                    Fl_Input_Choice* o = new Fl_Input_Choice(25, 70, 175, 30, "@-3circle  端口");
                    o->color(FL_LIGHT2);
                    o->selection_color(FL_LIGHT2);
                    o->labelfont(1);
                    o->labelsize(15);
                    o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                } // Fl_Input_Choice* o
                {
                    Fl_Input_Choice* o = new Fl_Input_Choice(25, 125, 175, 30, "@-3circle  波特率(bps)");
                    o->color(FL_LIGHT2);
                    o->selection_color(FL_LIGHT2);
                    o->labelfont(1);
                    o->labelsize(15);
                    o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                    o->menu(menu_3circle);
                } // Fl_Input_Choice* o
                {
                    buttonToSocket = new Fl_Button(25, 165, 85, 30, "切换套接字");
                    buttonToSocket->color(FL_LIGHT2);
                    buttonToSocket->labelfont(1);
                    buttonToSocket->callback((Fl_Callback*)cb_buttonToSocket);
                } // Fl_Button* buttonToSocket
                {
                    Fl_Light_Button* o = new Fl_Light_Button(120, 165, 80, 30, "打开");
                    o->box(FL_THIN_UP_BOX);
                    o->color(FL_LIGHT2);
                    o->selection_color(FL_GREEN);
                    o->labelfont(1);
                    o->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
                } // Fl_Light_Button* o
                groupConnectSerial->end();
            } // Fl_Group* groupConnectSerial
            wizardConnect->end();
        } // Fl_Wizard* wizardConnect
        {
            buttonRead = new Fl_Button(20, 215, 180, 50, "@refresh    读取所有参数");
            buttonRead->box(FL_THIN_UP_BOX);
            buttonRead->color(FL_LIGHT2);
            buttonRead->labelfont(1);
            buttonRead->callback((Fl_Callback*)cb_buttonRead);
        } // Fl_Button* buttonRead
        {
            buttonCopy = new Fl_Button(20, 275, 180, 50, "@filenew    复制所有参数");
            buttonCopy->box(FL_THIN_UP_BOX);
            buttonCopy->color(FL_LIGHT2);
            buttonCopy->labelfont(1);
        } // Fl_Button* buttonCopy
        {
            buttonWrite = new Fl_Button(20, 335, 180, 50, "@2->|    写入所有参数");
            buttonWrite->box(FL_THIN_UP_BOX);
            buttonWrite->color(FL_LIGHT2);
            buttonWrite->labelfont(1);
        } // Fl_Button* buttonWrite
        {
            buttonCustom = new Fl_Button(20, 395, 180, 50, "@<->    自定义按钮1");
            buttonCustom->box(FL_THIN_UP_BOX);
            buttonCustom->color(FL_LIGHT2);
            buttonCustom->labelfont(1);
        } // Fl_Button* buttonCustom
        {
            iniTable = new WidgetTable(220, 45, 485, 420, "参数列表");
            iniTable->box(FL_THIN_UP_FRAME);
            iniTable->color(FL_LIGHT3);
            iniTable->selection_color(FL_BACKGROUND_COLOR);
            iniTable->labeltype(FL_NO_LABEL);
            iniTable->labelfont(0);
            iniTable->labelsize(14);
            iniTable->labelcolor(FL_FOREGROUND_COLOR);
            iniTable->align(Fl_Align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE));
            iniTable->when(FL_WHEN_RELEASE);
            iniTable->end();
            Fl_Group::current()->resizable(iniTable);
        } // WidgetTable* iniTable
        windowMain->size_range(720, 480, 720, 480);
        windowMain->end();
    } // Fl_Double_Window* windowMain
    return windowMain;
}
