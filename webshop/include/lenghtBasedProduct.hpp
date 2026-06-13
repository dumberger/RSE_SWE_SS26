#pragma once

#include "product.hpp"

class LenghtBasedProduct : public Product {
public:
    LenghtBasedProduct(const std::string& name, double unitprice, double weight, double length);
    double getPrice() override;
private:
    double length;
};