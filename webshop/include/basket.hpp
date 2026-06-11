#pragma once

#include "product.hpp"

#include <map>

class Basket {
public:
    void addItem(Product* product, double quantity);
    void removeItem(Product* product);
    [[nodiscard]] const double checkout() const;
    void printItems() const;
private:
    std::map<Product*, double> items;
};