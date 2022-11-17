#include "pitch.h"

Pitch *Pitch::instance = nullptr;

Pitch &Pitch::get_instance()
{
    if (Pitch::instance == nullptr)
        Pitch::instance = new Pitch;
    return *Pitch::instance;
}

Pitch::Pitch()
{
    this->thread = std::thread(&Widget::begin_thread, this);
    this->thread.detach();
}

void Pitch::send()
{
    auto temp = std::abs(this->val - this->send_val);
    if (temp > SEPERATE)
        this->send_val = temp / (this->val - this->send_val) * SEPERATE;
    else
        this->send_val = val;
    Network::get_instance().sendPitch(this->send_val);
}