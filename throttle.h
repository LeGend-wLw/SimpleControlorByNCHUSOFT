#ifndef THROTTLE_H
#define THROTTLE_H

#include "widget.h"

#include "widget.cpp"

class Throttle : public Widget<>
{
  private:
    static Throttle *instance;

  private:
    Throttle();
    void send() override;

  public:
    static Throttle &get_instance();
    Throttle operator=(const Throttle &) = delete;
    ~Throttle() = default;
};

#endif // THROTTLE_H
