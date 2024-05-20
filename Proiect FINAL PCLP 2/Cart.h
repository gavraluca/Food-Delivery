#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"

class Cart {
public:
    void addProduct(Product* product);
    double getTotalPrice() const;
    void clearCart();
    std::vector<Product*> getProducts() const;

private:
    std::vector<Product*> products;
};

#endif // CART_H
