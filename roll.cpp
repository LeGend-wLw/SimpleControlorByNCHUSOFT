#include "roll.h"

Roll *Roll::instance = nullptr;

Roll &Roll::get_instance()
{
    if (Roll ::instance == nullptr)
        Roll::instance = new Roll;
    return *Roll::instance;
}

Roll::Roll()
{
    this->thread = std::thread(&Widget::begin_thread, static_cast<Widget *>(this));
    this->thread.detach();
}

void Roll::send()
{
    auto temp = std::abs(this->val - this->send_val);
    if (temp > SEPERATE)
        this->send_val = temp / (this->val - this->send_val) * SEPERATE;
    else
        this->send_val = val;
    Network::get_instance().sendRoll(this->send_val);
}
