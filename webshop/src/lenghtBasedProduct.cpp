#include "lenghtBasedProduct.hpp"

LengthBasedProduct::LengthBasedProduct(const std::string& name, double pricePerMeter, double length)
    : Product(name, pricePerMeter, length), pricePerMeter(pricePerMeter)
{}

double LengthBasedProduct::getPrice()
{
    return getUnitprice() * getWeight();
}
