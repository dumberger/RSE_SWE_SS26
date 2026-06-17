# include "../include/singelton.hpp"

const int& Singelton::get() const
{
    return _item;
}


int& Singelton::item()
{
    return _item;
}

const int& Singelton::item() const
{
    return _item;
}

Singelton& Singelton::getInstance()
{
    static Singelton s{};
    return s;
}

std::ostream& operator<<(std::ostream& os, const Singelton& s)
{
    os << s._item;
    return os;
}