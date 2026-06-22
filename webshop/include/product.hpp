#pragma once

#include <memory>
#include <string>

class Item;

class Product  : public std::enable_shared_from_this<Product> {
public:
    Product(const std::string& name, double unitprice, double weight);
    virtual ~Product() = default;
    virtual double getPrice() = 0;
    [[nodiscard]] const std::string getName() const { return name; }
    [[nodiscard]] const double getWeight() const { return weight; }
    virtual std::unique_ptr<Item> getItem(double quantity) = 0;
protected:
    [[nodiscard]] const double getUnitprice() const { return unitprice; }
private:
    std::string name;
    double unitprice;
    double weight;
};