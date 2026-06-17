#include "weightPriceProduct.hpp"
#include "product.hpp"

WeightPriceProduct::WeightPriceProduct(const std::string& name, double unitprice, double length)
: Product(name, unitprice, weight)
{}
    
double WeightPriceProduct::getPrice()
{
    return getUnitprice();
}