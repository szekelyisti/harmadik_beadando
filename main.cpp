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
            cout << "alma";
        }

        void event_loop()
        {
            event ev;
    Widget * selected = nullptr;

    for (size_t i = 0; i < 23; i++)
    {
        for(size_t j = 0; j < 23; j++)
        {
            if(i >= 4 && i <= 17 && j >= 4 && j <=17)
            {
                widgets[i+(j*23)]->draw();
            }
        }
    }
    gout << refresh;

    while(gin >> ev && ev.keycode != key_escape)
    {
        if(ev.type == ev_mouse)
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


        if (ev.type == ev_key)
        {
            if(ev.keycode == key_enter)
            {
                action("save");
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
            if(i >= 4 && i <= 17 && j >= 4 && j <=17)
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
        gout << color(255, 255, 255) << move_to(20, 20) << text("Jelenlegi játékos:");
        gout << text(to_string(player));
        gout << refresh;
    }
        }

    protected:

};

int main()
{
    gout.open(width, height);
    gout.showmouse(true);



    MyApplication app;

    app.event_loop();



    return 0;
}


