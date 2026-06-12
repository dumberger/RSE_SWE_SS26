#include "fixedPricedProduct.hpp"

int main() {
    FixedPriceProduct test;
    
    Product* prod = &test;

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