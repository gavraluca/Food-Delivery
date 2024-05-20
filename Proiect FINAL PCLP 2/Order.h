#ifndef ORDER_H
#define ORDER_H

#include "Cart.h"

class Order {
public:
    Order(const std::string& user, const Cart& cart);
    void confirmOrder();
    std::string getUser() const;
    Cart getCart() const;

private:
    std::string user;
    Cart cart;
    bool confirmed;
};

#endif // ORDER_H
