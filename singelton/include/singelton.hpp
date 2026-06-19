#pragma once
#include <iostream>

class Singelton {
public:
    // Rule of 5: Deaktivieren des Kopierens/Movens
    Singelton(const Singelton& other) = delete;
    Singelton& operator=(const Singelton& other) = delete;
    Singelton(Singelton&& other) = delete;
    Singelton& operator=(Singelton&& other) = delete;

    const int& get() const;
    void set(const int& value){_item = value;} //automatisch inline keyword

    int& item();
    const int& item() const;

    static Singelton& getInstance();

    // Friend-Deklaration
    friend std::ostream& operator<<(std::ostream& os, const Singelton& s);

private:
    Singelton() = default;
    int _item;
};

//std::ostream& operator<<(std::ostream& os, const Singelton& s);