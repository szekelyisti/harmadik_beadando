#include "graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "widget.hpp"
#include "check.hpp"
#include "application.hpp"
#include "amoba.hpp"
#include "box.hpp"

using namespace genv;
using namespace std;

const int width = 800;
const int height = 800;
int play_num = 1;
int player = 1;




class GameMaster
{
    protected:
        Application * _parent;
    public:
        GameMaster(Application * parent)
        {
            _parent = parent;
        }
        void winner()
        {
            vector<Widget *> widgets = _parent->getwidgets();
            for(size_t i = 4; i <=18; i++)
            {
                for(size_t j = 4; j <= 18; j++)
                {
                    if(widgets[i+(j*23)]->get_num() == 1 &&
                       widgets[i+1+(j*23)]->get_num() == 1 &&
                       widgets[i+2+(j*23)]->get_num() == 1 &&
                       widgets[i+3+(j*23)]->get_num() == 1 &&
                       widgets[i+4+(j*23)]->get_num() == 1)
                    {
                        _parent->action("one");
                    }
                    else if(widgets[i+(j*23)]->get_num() == 1 &&
                       widgets[i+((j+1)*23)]->get_num() == 1 &&
                       widgets[i+((j+2)*23)]->get_num() == 1 &&
                       widgets[i+((j+3)*23)]->get_num() == 1 &&
                       widgets[i+((j+4)*23)]->get_num() == 1)
                    {
                        _parent->action("one");
                    }
                    else if(widgets[i+(j*23)]->get_num() == 1 &&
                       widgets[i+1+((j+1)*23)]->get_num() == 1 &&
                       widgets[i+2+((j+2)*23)]->get_num() == 1 &&
                       widgets[i+3+((j+3)*23)]->get_num() == 1 &&
                       widgets[i+4+((j+4)*23)]->get_num() == 1)
                    {
                        _parent->action("one");
                    }
                    else if(widgets[i+(j*23)]->get_num() == 1 &&
                       widgets[i+1+((j-1)*23)]->get_num() == 1 &&
                       widgets[i+2+((j-2)*23)]->get_num() == 1 &&
                       widgets[i+3+((j-3)*23)]->get_num() == 1 &&
                       widgets[i+4+((j-4)*23)]->get_num() == 1)
                    {
                        _parent->action("one");
                    }
                    else if(widgets[i+(j*23)]->get_num() == 2 &&
                       widgets[i+1+(j*23)]->get_num() == 2 &&
                       widgets[i+2+(j*23)]->get_num() == 2 &&
                       widgets[i+3+(j*23)]->get_num() == 2 &&
                       widgets[i+4+(j*23)]->get_num() == 2)
                    {
                        _parent->action("two");
                    }
                    else if(widgets[i+(j*23)]->get_num() == 2 &&
                       widgets[i+((j+1)*23)]->get_num() == 2 &&
                       widgets[i+((j+2)*23)]->get_num() == 2 &&
                       widgets[i+((j+3)*23)]->get_num() == 2 &&
                       widgets[i+((j+4)*23)]->get_num() == 2)
                    {
                        _parent->action("two");
                    }
                    else if(widgets[i+(j*23)]->get_num() == 2 &&
                       widgets[i+1+((j+1)*23)]->get_num() == 2 &&
                       widgets[i+2+((j+2)*23)]->get_num() == 2 &&
                       widgets[i+3+((j+3)*23)]->get_num() == 2 &&
                       widgets[i+4+((j+4)*23)]->get_num() == 2)
                    {
                        _parent->action("two");
                    }
                    else if(widgets[i+(j*23)]->get_num() == 2 &&
                       widgets[i+1+((j-1)*23)]->get_num() == 2 &&
                       widgets[i+2+((j-2)*23)]->get_num() == 2 &&
                       widgets[i+3+((j-3)*23)]->get_num() == 2 &&
                       widgets[i+4+((j-4)*23)]->get_num() == 2)
                    {
                        _parent->action("two");
                    }
                }
            }
        }

        void tie()
        {
            vector<Widget *> widgets = _parent->getwidgets();
            int free = 0;
            for(Widget *w: widgets)
            {
                if(w->is_free())
                {
                    free++;
                }
            }
            if(free == 0)
            {
                _parent->action("tie");
            }
        }
};

class MyApplication : public Application
{
     public:
        MyApplication() : Application()
        {
            Amoba * am;
            for(size_t i = 0; i < 23; i++)
            {
                for(size_t j = 0; j < 23; j++)
                {
                    am = new Amoba(this, (width/23)*i, (height/23)*j, width/23, height/23);
                    registerWidget(am);
                }
            }
            box = new Box(this, 5, 5, 0, 50, "");
            registerWidget(box);
            endgame = new Box(this, width/3, height/2, 0, 50, "");
            registerWidget(endgame);
        }

        void action(string s)
        {
            if(s == "one")
            {
                game_over == true;
                gout << color(0, 0, 0) << move_to (0, 0) << box_to(width-1, height-1);
                endgame->setlabel("A gyoztes az elso jatekos!");
                endgame->draw();
            }

            if(s == "two")
            {
                game_over == true;
                gout << color(0, 0, 0) << move_to (0, 0) << box_to(width-1, height-1);
                endgame->setlabel("A gyoztes a masodik jatekos!");
                endgame->draw();
            }

            if(s == "tie")
            {
                game_over == true;
                gout << color(0, 0, 0) << move_to (0, 0) << box_to(width-1, height-1);
                endgame->setlabel("A jatek dontetlen!");
                endgame->draw();
            }
        }

        void event_loop()
        {
            event ev;
    Widget * selected = nullptr;

    for (size_t i = 0; i < 23; i++)
    {
        for(size_t j = 0; j < 23; j++)
        {
            if(i >= 4 && i <= 18 && j >= 4 && j <=18)
            {
                widgets[i+(j*23)]->draw();
            }
        }
    }
    gout << refresh;

    while(gin >> ev && ev.keycode != key_escape)
    {
        if(ev.type == ev_mouse && !game_over)
        {
            if(ev.button == btn_left)
            {
                selected = nullptr;
                for(Widget * w: widgets)
                {
                    w->deselect();
                }

                for(Widget * w: widgets)
                {
                    if(w->is_selected(ev.pos_x, ev.pos_y))
                    {
                        w->select();
                        selected = w;
                        if(w->is_free())
                        {
                        play_num++;
                        }
                        if(play_num%2 == 0)
                        {
                            player = 2;
                        }
                        else
                        {
                            player = 1;
                        }
                    }
                }
                for(Widget * w: widgets)
                {
                    if(w->is_free() && selected->is_free())
                    {
                        w->setplayer();
                    }
                }


                }
                if(selected)
                {
                    selected->handle(ev);
                }

        }

        for (size_t i = 0; i < 23; i++)
    {
        for(size_t j = 0; j < 23; j++)
        {
            if(i >= 4 && i <= 18 && j >= 4 && j <=18)
            {
                widgets[i+(j*23)]->draw();
            }
            else
            {
                widgets[i+(j*23)]->locker();
            }
        }
    }
        string s = "Jelenlegi jatekos: " + to_string(player);
        box->setlabel(s);
        box->draw();
        gm->winner();
        gm->tie();
        gout << refresh;
    }
        }

    vector<Widget *> getwidgets()
    {
        return widgets;
    }

    protected:
        GameMaster * gm = new GameMaster(this);
        bool game_over = false;
        Box * box;
        Box * endgame;

};

int main()
{
    gout.open(width, height);
    gout.showmouse(true);



    MyApplication app;

    app.event_loop();



    return 0;
}


