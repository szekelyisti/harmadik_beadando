#include <iostream>
#include <vector>
#include <string>
#include "graphics.hpp"
#include "box.hpp"
#include "application.hpp"

Box::Box(Application * parent, int x, int y, int sx, int sy, string label)
        : Widget(parent, x, y, sx, sy), _label(label)
{
    _sx = gout.twidth(label)+10;
    _sy = gout.cascent()+gout.cdescent()+10;
    if(_parent)
    {
        _parent->registerWidget(this);
    }
}

void Box::draw()
{
    if(_selected)
    {
        gout << color(255, 0, 0);
        gout << move_to(_x, _y);
        gout << box(_sx, _sy);
        gout << color(0, 0, 0);
        gout << move_to(_x+2, _y+2);
        gout << box(_sx-4, _sy-4);
        gout << move_to(_x+5, _y+(gout.cascent()+gout.cdescent()));
        gout << color(255, 0, 0);
        gout << text(_label);
    }
    if(!_selected)
    {
        gout << color(255, 255, 255);
        gout << move_to(_x, _y);
        gout << box(_sx, _sy);
        gout << color(0, 0, 0);
        gout << move_to(_x+2, _y+2);
        gout << box(_sx-4, _sy-4);
        gout << move_to(_x+5, _y+(gout.cascent()+gout.cdescent()));
        gout << color(255, 255, 255);
        gout << text(_label);
    }
}

bool Box::clicked(event ev)
{
    return ev.pos_x > _x && ev.pos_x < _x+_sx && ev.pos_y > _y && ev.pos_y < _y+_sy && ev.button == btn_left;
}

bool Box::is_selected(int mx, int my)
{
    return mx > _x && mx < _sx+_x && my > _y && my < _y+_sy;
}

void Box::handle(event ev)
{

}

string Box::getlabel()
{
    return _label;
}


void Box::setlabel(string label)
{
    _label = label;
    _sx = gout.twidth(label)+10;
    _sy = gout.cascent()+gout.cdescent()+10;
}

bool Box::is_free()
{

}

void Box::locker()
{

}

int Box::get_num()
{

}
