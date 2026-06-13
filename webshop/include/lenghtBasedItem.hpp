#pragma once
#include "item.hpp"
#include "product.hpp"

class LengthBasedItem : public Item {
public:
  LengthBasedItem(std::shared_ptr<Product> product, double quantity)
      : Item(product), quantity(quantity) {}
  double getPrice() override { return quantity * product->getPrice(); }
  double getLength() { return quantity; }

private:
  double quantity;
};