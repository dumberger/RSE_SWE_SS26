#include "singleton.hpp"

int Singleton::get() const {
    return item;
}

void Singleton::set(const int& value) {
    item = value;
}