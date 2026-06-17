#include "../include/basket.hpp"
#include <iostream>


void Basket::addItem(std::shared_ptr<Product> product, double quantity)
{
    items[product] += quantity;
}

void Basket::removeItem(std::shared_ptr<Product> product)
{
    items.erase(product);
}

const double Basket::checkout() const
{
    double price_suml = 0.0;
    double weight_suml = 0.0;

    for (auto& [product, quantity] : items) 
    {
        price_suml += product->getPrice() * quantity;
        weight_suml += product->getWeight() * quantity;
    }
    double shipping = 5.0 + 0.2 * weight_suml; 
    return price_suml + shipping;
}

void Basket::printItems() const
{
    for (auto& [product, quantity] : items) 
    {
        std::cout << product->getName() << ": " << quantity << "\n";
    }
}




