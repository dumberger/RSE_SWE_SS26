#pragma once

#include "product.hpp"
#include "item.hpp"

#include <map>
#include <cstdint>
#include <memory>

class Shop 
{
public:
    void addProduct(uint32_t id, std::unique_ptr<Product> product);
    void removeProduct(uint32_t id);
    std::shared_ptr<Item> getItem(uint32_t id, double quantity);
    void listProducts();
private:
    std::map<uint32_t, std::shared_ptr<Product>> catalogue;
};