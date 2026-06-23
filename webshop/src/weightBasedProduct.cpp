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

std::unique_ptr<Item> WeightBasedProduct::getItem(double quantity) { //(2) in class diagram
    auto item = std::make_unique<WeightBasedItem>(shared_from_this(), quantity); //(3) in class diagram
    return item; //(4) in class diagram
}