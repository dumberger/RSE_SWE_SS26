#pragma once

#include <memory>
#include "product.hpp"

class Item {
public:
    Item(std::shared_ptr<Product> product):product(product) {};
    virtual double getPrice();
    virtual double getWeight();
protected:
    std::shared_ptr<Product> product;
};