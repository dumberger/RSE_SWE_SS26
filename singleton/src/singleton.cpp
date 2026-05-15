#include "singleton.hpp"

const int& Singleton::get() const
{
    return _item;
}

int& Singleton::item() {
    return _item;
}

const int& Singleton::item() const {
    return _item;
}

Singleton& Singleton::getInstance()
{
    static Singleton s{};
    return s;
}

std::ostream& operator<<(std::ostream& os, const Singleton& s) {
    os << s._item;
    return os;
}