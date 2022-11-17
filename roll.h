#ifndef ROLL_H
#define ROLL_H

#include "widget.h"

#include "widget.cpp"
class Roll : public Widget<>
{
  public:
    static Roll &get_instance();
    virtual void send() override;
    Roll operator=(const Roll &) = delete;

  private:
    static Roll *instance;
    Roll();
    ~Roll() = default;
};

#endif // ROLL_H
