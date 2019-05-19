#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED


#include<vector>
#include<string>
#include "widget.hpp"


class Application
{
    protected:
        std::vector<Widget *> widgets;
    public:
        Application(){};
        virtual ~Application(){}
        void registerWidget(Widget *);
        void event_loop();
        virtual void action(std::string) = 0;

};


#endif // APPLICATION_HPP_INCLUDED
