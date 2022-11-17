#ifndef YAW_H
#define YAW_H

#include "widget.h"

#include "widget.cpp"

class YAW : public Widget<>
{
  private:
    static YAW *instance;

  private:
    YAW();
    void send() override;

  public:
    static YAW &get_instance();
    YAW operator=(const YAW &) = delete;
    ~YAW() = default;
};

#endif // YAW_H
