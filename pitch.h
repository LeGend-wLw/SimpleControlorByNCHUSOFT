#ifndef PITCH_H
#define PITCH_H

#include "widget.h"

#include "widget.cpp"

class Pitch : public Widget<>
{
  private:
    static Pitch *instance;
    virtual void send() override;
    Pitch();

  public:
    static Pitch &get_instance();
    Pitch operator=(const Pitch &) = delete;
    ~Pitch() = default;
};

#endif // PITCH_H
