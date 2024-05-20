#include "Order.h"

Order::Order(const std::string& user, const Cart& cart)
    : user(user), cart(cart), confirmed(false) {}

void Order::confirmOrder() {
    confirmed = true;
}

std::string Order::getUser() const {
    return user;
}

Cart Order::getCart() const {
    return cart;
}
