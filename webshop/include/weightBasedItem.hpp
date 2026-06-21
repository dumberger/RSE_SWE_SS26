#pragma once

#include "item.hpp"
#include "product.hpp"

class WeightBasedItem : public Item {
public:
  WeightBasedItem(std::shared_ptr<Product> product, double quantity)
      : Item(product), quantity(quantity) {};
  double getPrice() override { return quantity * product->getPrice(); }
  double getWeight() override { return quantity; }

private:
  double quantity;
};