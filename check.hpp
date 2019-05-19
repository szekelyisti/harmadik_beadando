#ifndef CHECK_HPP_INCLUDED
#define CHECK_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class Checkbox : public Widget
{
    protected:
        bool _checked = false;
    public:
        Checkbox(Application *, int x, int y, int sx, int sy);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual bool is_checked();
        virtual void setplayer(int);
};

#endif // CHECK_HPP_INCLUDED
