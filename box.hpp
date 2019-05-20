#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED

#include<iostream>
#include<string>
#include "graphics.hpp"
#include "widget.hpp"

class Box : public Widget
{
    protected:
        string _label;
    public:
        Box(Application *, int x, int y, int sx, int sy, string label);
        void draw();
        bool is_selected(int mx, int my);
        void handle(event ev);
        void setlabel(string label);
        bool clicked(event ev);
        string getlabel();
        bool is_free();
        void locker();
        int get_num();
};

#endif // BOX_HPP_INCLUDED
