#include "throttle.h"

Throttle *Throttle::instance = nullptr;

Throttle &Throttle::get_instance()
{
    if (Throttle::instance == nullptr)
        Throttle::instance = new Throttle;
    return *Throttle::instance;
}

Throttle::Throttle()
{
    this->thread = std::thread(&Widget::begin_thread, static_cast<Widget *>(this));
    this->thread.detach();
}

void Throttle::send()
{
    auto temp = std::abs(this->val - this->send_val);
    if (temp > SEPERATE)
        this->send_val = temp / (this->val - this->send_val) * SEPERATE;
    else
        this->send_val = val;
    Network::get_instance().sendTh(this->send_val);
}