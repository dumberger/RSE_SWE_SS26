#include "fixedPricedProduct.hpp"
#include "weightBasedProduct.hpp"
#include "lenghtBasedProduct.hpp"
#include "shop.hpp"
#include "basket.hpp"

int main() {
    FixedPriceProduct test1{"test1", 1, 1};
    WeightBasedProduct test2{"test2", 1, 1};
    LenghtBasedProduct test3{"test3", 1, 1, 1.000};
    
    Product* prod = &test1;

    return 0;
}

/*class Person; Name, Age, ..., getIdentification
class Student : public Person; getIdentification -> Matrickelnummer

verify(const Person& p)*/

/*
Webshop -> Produkte
Produkte:
    - FixedPricedProducts -> price per piece
    - WeightBasedProduct -> price per kg
    - LengthBasedProduct -> price per meter

user can select multiple objects from a catalog and put them into his basked
at checkout shipping costs will be calculated based on weight: 5€ + 0.20€ per kg
*/