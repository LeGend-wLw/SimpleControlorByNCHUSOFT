#ifndef WIDGET_H
#define WIDGET_H

#include "network.h"
#include <basetsd.h>
#include <chrono>
#include <thread>

template <typename T = INT16> class Widget
{
  public:
    void assign(T val);

  protected:
    Widget();

    static void begin_thread(Widget *widget);

    std::thread thread;
    virtual ~Widget();
    virtual void send() = 0;
    volatile T val;
    volatile T send_val;

  protected:
    volatile bool stop;
};

#endif // WIDGET_H
