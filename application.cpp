#include "application.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include<fstream>
#include<string>
#include<vector>

using namespace genv;
using namespace std;

void Application::registerWidget(Widget * w)
{
    widgets.push_back(w);
}

void Application::event_loop()
{
    event ev;
    Widget * selected = nullptr;

    gout << color(255, 255, 255) << move_to(20, 20) << text("Az enter lenyomásával lehet az adatokat a fájlba írni.") << refresh;

    for (Widget * w : widgets)
    {
        w->draw();
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

        for (Widget * w : widgets)
        {
            w->draw();
        }
        gout << refresh;
    }
}
