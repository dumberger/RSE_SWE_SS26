#pragma once

#include <string>

class Product 
{
public:
    Product(const std::string& name, double unitprice, double weight);
    virtual ~Product() = default;
    virtual double getPrice() = 0;
    [[nodiscard]] const std::string getName() const { return name; }
    [[nodiscard]] const double getWeight() const { return weight; }

protected:
    [[nodiscard]] const double getUnitprice() const { return unitprice; }

private:
    std::string name;
    double unitprice;
    double weight;
};