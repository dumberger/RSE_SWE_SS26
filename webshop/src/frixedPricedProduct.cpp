#include "fixedPricedProduct.hpp"

FixedPriceProduct::FixedPriceProduct(const std::string& name, double unitprice, double weight)
: Product(name, unitprice, weight)
{

}

double FixedPriceProduct::getPrice()
{
    return getUnitprice();
}