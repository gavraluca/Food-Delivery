#ifndef FOODDELIVERYSYSTEM_H
#define FOODDELIVERYSYSTEM_H

#include <vector>
#include "User.h"
#include "Store.h"
#include "Cart.h"
#include "Order.h"

class FoodDeliverySystem {
public:
    void run();

private:
    bool login(User& user);
    void initializeStores();
    Store* chooseStore();
    void shop(Store* store, Cart& cart);
    void placeOrder(User& user, Cart& cart);

    std::vector<Store*> stores;
};

#endif // FOODDELIVERYSYSTEM_H

