#pragma once
#include <istream>

class Singleton{
    public:
        //Singleton() = default; //default constructor
        Singleton(const Singleton& other) = delete;
        Singleton& operator=(const Singleton& other) = delete;
        Singleton(Singleton&& other) = delete;
        Singleton& operator=(Singleton&& other) = delete;


        const int& get() const;
        void set(const int& value) {_item = value; }

        int& item(); // can be modified
        const int& item() const; // can not be modified

        static Singleton& getInstance(); // pin there function not to an object but to the class itself
        friend std::iostream& operator<<(std::iostream& os, const Singleton& s); 
        //friend allows to have an accees to private for this function/class
        //also defines the function here. Implementation in .cpp
    private:
        Singleton() = default; // to make only one object (more not allowed)
        int _item;

};

// inline void Singleton::set(const int& value){
//     _item = value;
// }