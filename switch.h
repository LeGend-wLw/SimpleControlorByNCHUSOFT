#ifndef SWITCH_H
#define SWITCH_H
#include "widget.h"

#include "widget.cpp"

class Switch : public Widget<bool>
{
  private:
    static Switch *instance;

  private:
    Switch();
    void send() override;

  public:
    bool get_val();
    static Switch &get_instance();
    Switch operator=(const Switch &) = delete;
    ~Switch() = default;
};

#endif // SWITCH_H
