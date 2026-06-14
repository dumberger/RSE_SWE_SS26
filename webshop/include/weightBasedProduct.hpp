#pragma once

#include "product.hpp"

class WeightPriceProduct : public Product {
public:
    WeightPriceProduct(const std::string& name, double unitprice, double weight);
    double getPrice() override;
private:
};