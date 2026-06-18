#include "weightBasedProduct.hpp"

WeightBasedProduct::WeightBasedProduct(const std::string& name, double pricePerKg, double weight)
    : Product(name, pricePerKg, weight), pricePerKg(pricePerKg)
{}

double WeightBasedProduct::getPrice()
{
    return getUnitprice() * getWeight();
}
