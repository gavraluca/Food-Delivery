#include <iostream>
#include <cassert>
#include "User.h"
#include "Store.h"
#include "Product.h"
#include "Cart.h"
#include "Order.h"


void testUserAuthentication() {
    User user("testuser", "password");
    assert(user.authenticate("password") == true);
    assert(user.authenticate("wrongpassword") == false);
}

void testProductManagement() {
    Product product("Apple", 0.5, 100);
    assert(product.getName() == "Apple");
    assert(product.getPrice() == 0.5);
    assert(product.getStock() == 100);
    product.reduceStock(10);
    assert(product.getStock() == 90);
}

void testStoreManagement() {
    GroceryStore store("Test Store");
    Product apple("Apple", 0.5, 100);
    store.addProduct(&apple);
    Product* product = store.getProduct("Apple");
    assert(product != nullptr);
    assert(product->getName() == "Apple");
}

void testCartManagement() {
    Cart cart;
    Product apple("Apple", 0.5, 100);
    cart.addProduct(&apple);
    assert(cart.getTotalPrice() == 0.5);
    assert(cart.getProducts().size() == 1);
}

void testOrderManagement() {
    Cart cart;
    Product apple("Apple", 0.5, 100);
    cart.addProduct(&apple);
    Order order("testuser", cart);
    order.confirmOrder();
    assert(order.getUser() == "testuser");
    assert(order.getCart().getTotalPrice() == 0.5);
}

void testMultipleStores() {
    GroceryStore store1("Store 1");
    GroceryStore store2("Store 2");

    Product apple("Apple", 0.5, 100);
    Product banana("Banana", 0.3, 150);

    store1.addProduct(&apple);
    store2.addProduct(&banana);

    assert(store1.getProduct("Apple") != nullptr);
    assert(store1.getProduct("Banana") == nullptr);
    assert(store2.getProduct("Banana") != nullptr);
    assert(store2.getProduct("Apple") == nullptr);
}

int main() {
    testUserAuthentication();
    testProductManagement();
    testStoreManagement();
    testCartManagement();
    testOrderManagement();
    testMultipleStores();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
