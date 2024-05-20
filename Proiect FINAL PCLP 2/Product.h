#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(const std::string& name, double price, int stock);
    std::string getName() const;
    double getPrice() const;
    int getStock() const;
    void reduceStock(int amount);

private:
    std::string name;
    double price;
    int stock;
};

#endif // PRODUCT_H

