#include "basket.hpp"
#include <iostream>

void Basket::addItem(Product* product, double quantity)
{
    items[product] += quantity;
}

void Basket::removeitem(Product* product)
{
    items.erase(product);
}

const double Basket::checkout() const
{
    double price_sum = 0;
    double weight_sum = 0;
    for(auto& [product, quantity] : items){
        price_sum += product->getUnitprice() * quantity;
        weight_sum += product->getWeight() * quantity;
    }    
    double shipping = 5.00 + 0.2 * weight_sum;
    return price_sum + shipping;
}

void Basket::printItems()
{
    for(auto& [product, quantity] : items){
        std::cout << product->getName() << ": " << quantity << "\n";
    }
}