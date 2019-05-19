#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <iostream>

using namespace std;
using namespace genv;

class Application;

class Widget
{
    protected:
        int _x, _y, _sx, _sy, _play_num;
        bool _selected = false;
        Application * _parent;
    public:
        Widget(Application *, int, int, int, int);
        void select();
        void deselect();
        virtual void draw() = 0;
        virtual bool is_selected(int, int);
        virtual void handle(event ev) = 0;
        virtual void setplayer();
        virtual int get_play();
        virtual bool is_free() = 0;
        virtual void locker() = 0;
        virtual int get_num() = 0;
};


#endif // WIDGET_HPP_INCLUDED
