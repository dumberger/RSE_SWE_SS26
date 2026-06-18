#pragma once

#include <memory>
#include "product.hpp"

class Item {
public:
    Item(std::shared_ptr<Product> product) : product(product) {};
    virtual double getPrice() = 0;
    virtual double getWeight() = 0;
    std::string getName() {return product->getName();}
protected:    
    std::shared_ptr<Product> product;
};