// class lenghtBasedProduct
//  public Product
//  price() override
//  length

// TODO

#pragma once
#include "product.hpp"

class LengthBasedProduct : public Product {

public:
  LengthBasedProduct(const std::string &name, double pricePerMeter)
      : Product(name, pricePerMeter, 0.0) {}
  double getPrice() override { return getUnitprice(); }
};