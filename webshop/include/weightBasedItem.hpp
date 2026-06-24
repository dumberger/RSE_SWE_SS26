#pragma once


#include <memory>
#include "Item.hpp"

class WeightBasedItem : public Item {

    public:
        WeightBasedItem(std::shared_ptr<Product> product, double quantity) : Item(product), quantity(quantity) {};
        double getPrice() override {return quantity / product->getWeight() * product->getPrice();}
        double getWeight() override {return product->getWeight() * quantity;}

    private:
        double quantity;
};