#include "shop.hpp"

#include <iostream>

void Shop::addProduct(uint32_t id, Product* product)
{
    catalogue[id] = product;
}

void Shop::removeProduct(uint32_t id)
{
    delete catalogue[id];
    catalogue.erase(id);
}

Product* Shop::getProduct(uint32_t id)
{
    return catalogue[id];
}

void Shop::listProducts()
{
    for (auto& [id, product] : catalogue) {
        std::cout << id << ": " << product->getName() << "\n";
    }
}