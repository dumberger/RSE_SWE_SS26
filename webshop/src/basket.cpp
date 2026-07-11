#include "basket.hpp"

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
    double price_sum = 0;
    double weight_sum = 0;
    for (auto& [product, quantity] : items) {
        price_sum += product->getPrice() * quantity;
        weight_sum += product->getWeight() * quantity;
    }
    double shipping = 5.00 + 0.20 * weight_sum;
    return price_sum + shipping;
}

void Basket::printItems() const
{
    for (auto& [product, quantity] : items) {
        std::cout << product->getName() << ": " << quantity << "\n";
    }
}
