#pragma once

class Product {
public:
    double getPrice();
private:
    std::string name;
    uint32_t id;
    double unitprice;
    double weight;
};