#include "basket.hpp"
#include "fixedPricedProduct.hpp"
#include "shop.hpp"
#include "weightBasedProduct.hpp"
#include <atomic>
#include <iostream>
#include <memory>

int main() {
    Shop shop;
    Basket basket;
    shop.addProduct(1, std::make_unique<FixedPriceProduct>("laptop", 3100, 5));
    shop.addProduct(2, std::make_unique<FixedPriceProduct>("apple", 1.5, 0.3));
    shop.addProduct(3, std::make_unique<WeightPriceProduct>("meatloaf", 0.99, 0.1));
    shop.addProduct(4, std::make_unique<WeightPriceProduct>("garden earth", 12.99, 25));
    
    while(std::cin.good()) {
        uint32_t id;
        double quantity;
        shop.listProducts();
        std::cout << "select a product by id and specify quantity:";
        std::cin >> id >> quantity;
        if(quantity == 0.0) {
            break;
        }
        auto item = shop.getItem(id, quantity);
        if(item) {
            basket.addItem(std::move(item), quantity);
        }
    }
    std::cout << "\n\nYour order:\n";
    basket.printItems();
    auto final_price = basket.checkout();
    std::cout << std::endl;
    return 0;
}