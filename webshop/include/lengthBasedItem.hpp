#pragma once

#include "item.hpp"
#include "product.hpp"

class LengthPricedItem : public Item {
    FixedPricedItem(std::shared_ptr<Product> product) : Item(product) {};
    double getPrice() override { return product->getPrice(); }
    double getWeight() override { return product->getWeight(); };
};