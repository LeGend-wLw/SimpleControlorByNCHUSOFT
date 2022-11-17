#include "widget.h"

#ifndef WIDGET_CPP

#define WIDGET_CPP
template <typename T> Widget<T>::Widget()
{
    this->stop = false;
}

template <typename T> void Widget<T>::assign(T val)
{
    this->val = val;
}

template <typename T> void Widget<T>::begin_thread(Widget *widget)
{
    for (;;)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(WAITING_TIME));
        if (widget->stop)
            break;
        widget->send();
    }
}

template <typename T> Widget<T>::~Widget()
{
    this->stop = true;
}
#endif
