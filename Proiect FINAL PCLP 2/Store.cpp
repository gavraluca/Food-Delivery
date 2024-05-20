#include "Store.h"

GroceryStore::GroceryStore(const std::string& name)
    : name(name) {}

std::string GroceryStore::getName() const {
    return name;
}

void GroceryStore::addProduct(Product* product) {
    products.push_back(product);
}

Product* GroceryStore::getProduct(const std::string& productName) {
    for (Product* product : products) {
        if (product->getName() == productName) {
            return product;
        }
    }
    return nullptr;
}
