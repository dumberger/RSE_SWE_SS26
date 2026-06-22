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
    auto iterator = catalogue.find(id);
    if(iterator != catalogue.end()) {
        auto product = iterator->second;
        auto item = product->getItem(quantity); //(1) in class diagram
        return item; //(5) in class diagram
    } else {
        return nullptr;
    }
}

void Shop::listProducts()
{
    for (auto& [id, product] : catalogue) {
        std::cout << id << ": " << product->getName() << "\n";
    }
}