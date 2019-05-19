#include <iostream>
#include <vector>
#include <string>
#include "graphics.hpp"
#include "widget.hpp"

using namespace std;
using namespace genv;

Widget::Widget(Application * parent, int x, int y, int sx, int sy)
{
    _x = x;
    _y = y;
    _sx = sx;
    _sy = sy;
    _parent = parent;
}

bool Widget::is_selected(int mx, int my)
{
    return mx > _x && mx < _sx+_x && my > _y && my < _y+_sy;
}


void Widget::select()
{
    _selected = true;
}

void Widget::deselect()
{
    _selected = false;
}

int Widget::get_play()
{
    return _play_num;
}

void Widget::setplayer()
{
    _play_num++;
}
