#pragma once

#include "product.hpp"

class FixedPriceProduct : public Product 
{
public:
    FixedPriceProduct(const std::string& name, double unitprice, double weight);
    double getPrice() override;
};