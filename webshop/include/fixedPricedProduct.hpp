#pragma once

#include "product.hpp"

class FixedPriceProduct : public Product {
public:
    FixedPriceProduct(const std::string& name, double unitprice, double weight);
    double getPrice() override;
    std::unique_ptr<Item> getItem(double quantity) override;
};