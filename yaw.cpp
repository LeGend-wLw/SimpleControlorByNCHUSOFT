#include "yaw.h"

YAW *YAW::instance = nullptr;

YAW &YAW::get_instance()
{
    if (YAW::instance == nullptr)
        YAW::instance = new YAW;
    return *YAW::instance;
}

YAW::YAW()
{
    this->thread =
        std::thread(&Widget::begin_thread, static_cast<Widget *>(this));
    this->thread.detach();
}

void YAW::send()
{
    auto temp = std::abs(this->val - this->send_val);
    if (temp > SEPERATE)
        this->send_val = temp / (this->val - this->send_val) * SEPERATE;
    else
        this->send_val = val;
    Network::get_instance().sendYaw(this->send_val);
}
