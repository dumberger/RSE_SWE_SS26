#include "fixedPricedProduct.hpp"
#include "fixedPricedItem.hpp"
#include "product.hpp"
#include <memory>

FixedPriceProduct::FixedPriceProduct(const std::string& name, double unitprice, double weight)
: Product(name, unitprice, weight)
{}
    
double FixedPriceProduct::getPrice()
{
    return getUnitprice();
}

std::unique_ptr<Item> FixedPriceProduct::getItem(double quantity) {
    auto item = std::make_unique<FixedPricedItem>(shared_from_this());
    return item;
}