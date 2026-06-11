#pragma once
#include "product.hpp"
#include <vector>
#include <map>

class Basket {
public:
    void addItem(Product* product, double quantity);
    void removeitem(Product* product);
    [[nodiscard]] const double checkout() const;
    void printItems() ;
private:
    std::map<Product*, double> items;
};