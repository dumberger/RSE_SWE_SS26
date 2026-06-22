#include "weightBasedProduct.hpp"

WeightBasedProduct::WeightBasedProduct(const std::string& name, double unitprice, double weight)
: Product(name, unitprice, weight)
{}

double WeightBasedProduct::getPrice()
{
    return getUnitprice();
}