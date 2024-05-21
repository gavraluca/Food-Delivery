#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "Product.h"

class Store {
public:
    virtual ~Store() = default;
    virtual std::string getName() const = 0;
    virtual void addProduct(Product* product) = 0;
    virtual Product* getProduct(const std::string& productName) = 0;
};
