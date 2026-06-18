#pragma once

#include "product.hpp"

class WeightBasedProduct : public Product {
public:
    WeightBasedProduct(const std::string& name, double pricePerKg, double weight);
    double getPrice() override;
private:
    double pricePerKg;
};