#pragma once

#include "product.hpp"
#include <string> 

class LengthBasedProduct : public Product {
public:
    LengthBasedProduct(const std::string& name, double unitprice, double weight, double length): Product(name, unitprice, weight), length(length) {}

    double getPrice() override {
        return getUnitprice() * length; 
    }
    
private:
    double length;
};





//class lenghtBasedProduct
// public Product
// price() override
// length

//TODO