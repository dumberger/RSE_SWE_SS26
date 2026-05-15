#pragma once

class Singleton {
public:
    int get() const;
    void set(const int& value);
private:
    int item;

};
