#pragma once

#include "product.hpp"

class LengthBasedProduct : public Product {
public:
    LengthBasedProduct(const std::string& name, double pricePerMeter, double length);
    double getPrice() override;
private:
    double pricePerMeter;
};