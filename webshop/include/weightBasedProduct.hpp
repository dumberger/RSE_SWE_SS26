#pragma once

#include "product.hpp"

class WeightBasedProduct : public Product {
public:
    WeightBasedProduct(const std::string& name, double unitprice, double weight);
    double getPrice() override;
};