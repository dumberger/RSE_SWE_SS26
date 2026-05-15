#pragma once

#include <iostream>

class Singleton{
public:
    Singleton(const Singleton& other) = delete;
    Singleton& operator = (const Singleton& other) = delete;
    Singleton(Singleton&& other) = delete;
    Singleton& operator=(Singleton&& other) = delete;

    //const int& get() const();
    void set(const int& value);

    int& item();
    const int& item() const;

    static Singleton& getInstance();
    friend std::ostream& operator<<(std::ostream& os, const Singleton& s);
private:
    Singleton() = default;
    int _item;
};