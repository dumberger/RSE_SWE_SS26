#include "lenghtBasedProduct.hpp"

LenghtBasedProduct::LenghtBasedProduct(const std::string &name,
                                       double unitprice, double weight,
                                       double length)
    : Product(name, unitprice, weight), length(length) {}

double LenghtBasedProduct::getPrice() { return getUnitprice(); }