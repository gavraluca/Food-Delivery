#include "Cart.h"

void Cart::addProduct(Product* product) {
    products.push_back(product);
}
double Cart::getTotalPrice() const {
    double total = 0;
    for (Product* product : products) {
        total += product->getPrice();
    }
    return total;
}
