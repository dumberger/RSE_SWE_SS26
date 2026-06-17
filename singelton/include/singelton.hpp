#pragma once

#include <ostream>
class Singelton
{
public:
    Singelton(const Singelton& other) = delete;
    Singelton& operator=(const Singelton& other) = delete;
    Singelton(Singelton&& other) = delete;
    Singelton& operator=(Singelton&& other) = delete;

    const int& get() const;
    void set(const int& value)
    {
        _item = value;
    }

    int& item();
    const int& item() const;

    static Singelton& getInstance(); 

    friend std::ostream& operator<<(std::ostream& os, const Singelton& s); 

private:
    Singelton() = default;

    int _item;
};


