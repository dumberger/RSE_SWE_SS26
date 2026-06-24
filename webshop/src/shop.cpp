#include "shop.hpp"
#include "Item.hpp"
#include <iostream>
#include <memory>
#include <cstdint>


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

std::unique_ptr<Item> Shop::getProduct(uint32_t id, double quantity)
{
    return std::make_unique(catalogue[id], quantity);
}

void Shop::listProducts()
{
    for (auto& [id, product] : catalogue) {
        std::cout << id << ": " << product->getName() << "\n";
    }
}