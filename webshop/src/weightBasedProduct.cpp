#include "weightBasedProduct.hpp"
#include "weightBasedItem.hpp"
#include <memory>

WeightBasedProduct::WeightBasedProduct(const std::string& name, double unitprice, double weight)
: Product(name, unitprice, weight)
{}
    
double WeightBasedProduct::getPrice()
{
    return getUnitprice()/getWeight();
}

std::unique_ptr<Item> WeightBasedProduct::getItem(double quantity) {
    auto item = std::make_unique<WeightBasedItem>(shared_from_this(), quantity);
    return item;
}