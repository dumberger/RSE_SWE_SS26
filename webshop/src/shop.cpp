#include "shop.hpp"
#include "product.hpp"
#include "item.hpp"

#include <iostream>
#include <memory>

void Shop::addProduct(uint32_t id, std::unique_ptr<Product> product)
{
    if (product == nullptr) {
        return;
    }
    catalogue[id] = std::move(product);
}

void Shop::removeProduct(uint32_t id)
{
    catalogue.erase(id);
}

std::unique_ptr<Item> Shop::getItem(uint32_t id, double quantity)
{
    return std::make_unique(catalogue[id]);
}

void Shop::listProducts()
{
    for (auto& [id, product] : catalogue) {
        std::cout << id << ": " << product->getName() << "\n";
    }
}