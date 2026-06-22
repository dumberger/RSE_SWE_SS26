#pragma once

#include "item.hpp"

#include <map>
#include <memory>

class Basket {
public:
    void addItem(std::shared_ptr<Item> product, double quantity);
    void removeItem(std::shared_ptr<Item> product);
    [[nodiscard]] const double checkout() const;
    void printItems() const;
private:
    std::map<std::shared_ptr<Item>, double> items;
};