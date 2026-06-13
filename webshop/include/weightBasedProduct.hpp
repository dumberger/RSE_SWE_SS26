#pragma once
#include "product.hpp"

class WeightBasedProduct : public Product {

public:
  WeightBasedProduct(const std::string &name, double pricePerKg)
      : Product(name, pricePerKg, 0.0) {};
  double getPrice() override { return getUnitprice(); }
};