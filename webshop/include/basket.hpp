#pragma once

#include <map>
#include "product.hpp"
#include <memory>

class Basket 
{
public:
    void addItem(std::shared_ptr<Product> product, double quantity);
    void removeItem(std::shared_ptr<Product> product);
    [[nodiscard]] const double checkout() const;
    void printItems() const;
private:
    std::map<std::shared_ptr<Product>, double> items;
};