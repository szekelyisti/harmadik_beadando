#include "check.hpp"
#include "graphics.hpp"
using namespace genv;



Checkbox::Checkbox(Application * parent, int x, int y, int sx, int sy)
    : Widget(parent, x, y, sx, sy)
{
}

void Checkbox::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_sx-4, _sy-4);
    if (_checked)
    {
            gout << color(255,255,255);
            gout << move_to(_x+4, _y+4) << line(_sx-8, _sy-8);
            gout << move_to(_x+5, _y+4) << line(_sx-8, _sy-8);
            gout << move_to(_x+_sx-4, _y+4) << line(-_sx+8, _sy-8);
            gout << move_to(_x+_sx-5, _y+4) << line(-_sx+8, _sy-8);
    }
}

void Checkbox::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
    {
        _checked = !_checked;
    }
}
bool Checkbox::is_checked()
{
    return _checked;
}

void Checkbox::setplayer(int)
{

}
