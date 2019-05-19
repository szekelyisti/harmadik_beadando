#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "check.hpp"

class Amoba : public Checkbox
{
    protected:
        bool _free = true;
        int _play_num = 0;
        int _fix_num = 0;
    public:
        Amoba(Application *, int x, int y, int sx, int sy);
        void draw();
        void setplayer();
        void handle(event);
        int get_play();
        bool is_free();
        void locker();
};

#endif // AMOBA_HPP_INCLUDED
