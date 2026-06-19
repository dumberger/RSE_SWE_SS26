#pragma once

#include "product.hpp"
#include <memory>
class Item {

    public:
        Item(std::shared_ptr<Product> product) : product(product) {};
        virtual double getPrice() = 0;
        virtual double getWeight() = 0;

    protected:
        std::shared_ptr<Product> product;



};