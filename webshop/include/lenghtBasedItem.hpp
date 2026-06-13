#pragma once

#include "item.hpp"
#include "product.hpp"

class LenghtBasedItem : public Item {
public:
    LenghtBasedItem(std::shared_ptr<Product> product, double quantity) : Item(product), quantity(quantity) {};
    double getPrice() override { return quantity * product->getPrice(); }
    double getWeight() override { return quantity; }
private:
    double quantity;
};