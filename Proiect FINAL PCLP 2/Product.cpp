#include "Product.h"

Product::Product(const std::string& name, double price, int stock)
    : name(name), price(price), stock(stock) {}

std::string Product::getName() const {
    return name;
}
