#pragma once

#include "item.hpp"

class FixedPriceItem : public Item {
public:
    FixedPriceItem(std::shared_ptr<Product> product): Item(product) {};
    double getPrice() override { return product->getPrice(); };
    double getWeight() override { return product->getWeight(); };
};