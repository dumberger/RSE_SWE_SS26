#pragma once

#include "product.hpp"

#include <map>

class Shop {
public:
    void addProduct(uint32_t id, Product* product);
    void removeProduct(uint32_t id);
    Product* getProduct(uint32_t id);
    void listProducts();
private:
    std::map<uint32_t, Product*> catalogue;
};