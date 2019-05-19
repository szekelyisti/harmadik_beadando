#include "graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "widget.hpp"
#include "check.hpp"
#include "application.hpp"
#include "amoba.hpp"

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
        }

        void action(string s)
        {
            if(s == "one")
            {
                game_over == true;
                gout << move_to(0, 0) << color(0, 0, 0) << box(width-1, height-1);
                //gout << gout.load_font("LiberationMono-Bold.ttf", 50);
                gout << move_to(width/4, height/2-25) << color(255, 0, 0);
                gout << text("A gyoztes az elso jatekos!") << refresh;
            }

            if(s == "two")
            {
                game_over == true;
                gout << move_to(0, 0) << color(0, 0, 0) << box(width-1, height-1);
                //gout << gout.load_font("LiberationMono-Bold.ttf", 50);
                gout << move_to(width/4, height/2-25) << color(255, 0, 0);
                gout << text("A gyoztes a masodik jatekos!") << refresh;
            }

            if(s == "tie")
            {
                game_over == true;
                gout << move_to(0, 0) << color(0, 0, 0) << box(width-1, height-1);
                //gout << gout.load_font("LiberationMono-Bold.ttf", 50);
                gout << move_to(width/4, height/2-25) << color(255, 0, 0);
                gout << text("A jatek dontetlen!") << refresh;
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
        gout << color(0, 0, 0) << move_to(0, 0) << box(width/2, height/17-1);
        //gout << gout.load_font("LibarationMono-Bold.ttf", 16);
        gout << color(255, 255, 255) << move_to(20, 20) << text("Jelenlegi jatekos:");
        gout << text(to_string(player));
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

};

int main()
{
    gout.open(width, height);
    gout.showmouse(true);



    MyApplication app;

    app.event_loop();



    return 0;
}


