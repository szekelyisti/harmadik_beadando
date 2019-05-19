#include "amoba.hpp"
#include "graphics.hpp"
using namespace genv;

Amoba::Amoba(Application * parent, int x, int y, int sx, int sy)
    : Checkbox(parent, x, y, sx, sy)
{
}

void Amoba::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_sx-4, _sy-4);
    if (_checked && _play_num%2 == 1)
    {
        gout << color(0, 0, 255);
        gout << move_to(_x+4, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+5, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+_sx-4, _y+4) << line(-_sx+8, _sy-8);
        gout << move_to(_x+_sx-5, _y+4) << line(-_sx+8, _sy-8);
    }
    if(_checked && _play_num%2 == 0)
    {
        gout << color(0, 255, 0);
        gout << move_to(_x+_sx/2, _y+4) << line_to(_x+4, _y+_sy-4);
        gout << line_to(_x+_sx-4, _y+_sy-4) << line_to(_x+_sx/2, _y+4);
    }
}

void Amoba::setplayer()
{
    _play_num++;
}


void Amoba::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && _free)
    {
        _checked = !_checked;
        if(_play_num%2==0)
        {
            _fix_num = 2;
        }
        else
        {
            _fix_num = 1;
        }

        _free = false;
    }
}

int Amoba::get_play()
{
    return _play_num;
}

bool Amoba::is_free()
{
    return _free;
}

void Amoba::locker()
{
    _free = false;
}

int Amoba::get_num()
{
    return _fix_num;
}

/*bool Amoba::is_selected(int mx, int my)
{
    return mx > _x && mx < _sx+_x && my > _y && my < _y+_sy;
}*/
