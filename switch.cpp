#include "switch.h"

Switch *Switch::instance = nullptr;

void Switch::send()
{
    Network::get_instance().sendSw(this->val == 0);
}

Switch &Switch::get_instance()
{
    if (Switch::instance == nullptr)
        Switch::instance = new Switch;
    return *Switch::instance;
}

Switch::Switch()
{
    this->thread = std::thread(&Widget::begin_thread, this);
    this->val = false;
    this->send_val = false;
    this->thread.detach();
}

bool Switch::get_val()
{
    return this->val;
}
