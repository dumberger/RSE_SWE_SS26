#include "lengthBasedProduct.hpp"
#include "product.hpp"

LengthBasedProduct::LengthBasedProduct(const std::string& name, double unitprice, double weight, double length)
: Product(name, unitprice, weight)
{}
    
double LengthBasedProduct::getPrice()
{
    return getUnitprice();
}