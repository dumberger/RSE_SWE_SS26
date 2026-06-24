#pragma once

#include "Item.hpp"
#include <memory>

class FixedPricedItem : public Item {

    public:
        FixedPricedItem(std::shared_ptr<Product> product) : Item(product) {};
        double getPrice() override {return product->getPrice();}
        double getWeight() override {return product->getWeight();}
};