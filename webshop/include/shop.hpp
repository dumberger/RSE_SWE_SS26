#pragma once

#include "product.hpp"
#include <memory>
#include <algorithm>
#include <map>
#include <cstdint>
#include "Item.hpp"

class Shop {
public:
    void addProduct(uint32_t id, std::unique_ptr<Product> product);

    void removeProduct(uint32_t id);

    std::shared_ptr<Product> getProduct(uint32_t id);

    void listProducts();

private:

    std::map<uint32_t, std::shared_ptr<Product>> catalogue;
};