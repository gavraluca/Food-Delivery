#include <iostream>
#include <cassert>
#include "Test.h"
#include "User.h"
#include "Store.h"
#include "Product.h"
#include "Cart.h"
#include "Order.h"

void Test::testUserAuthentication() {
    User user("testuser", "password");
    assert(user.authenticate("password") == true);
    assert(user.authenticate("wrongpassword") == false);
}
void Test::testProductManagement() {
    Product product("Apple", 0.5, 100);
    assert(product.getName() == "Apple");
    assert(product.getPrice() == 0.5);
    assert(product.getStock() == 100);
    product.reduceStock(10);
    assert(product.getStock() == 90);
}
#include <iostream>
#include <cassert>
#include "Test.h"
#include "User.h"
#include "Store.h"
#include "Product.h"
#include "Cart.h"
#include "Order.h"

void Test::testUserAuthentication() {
    User user("testuser", "password");
    assert(user.authenticate("password") == true);
    assert(user.authenticate("wrongpassword") == false);
}

void Test::testProductManagement() {
    Product product("Apple", 0.5, 100);
    assert(product.getName() == "Apple");
    assert(product.getPrice() == 0.5);
    assert(product.getStock() == 100);
    product.reduceStock(10);
    assert(product.getStock() == 90);
}

void Test::testStoreManagement() {
    GroceryStore store("Test Store");
    Product apple("Apple", 0.5, 100);
    store.addProduct(&apple);
    Product* product = store.getProduct("Apple");
    assert(product != nullptr);
    assert(product->getName() == "Apple");
}

void Test::testCartManagement() {
    Cart cart;
    Product apple("Apple", 0.5, 100);
    cart.addProduct(&apple);
    assert(cart.getTotalPrice() == 0.5);
    assert(cart.getProducts().size() == 1);
}

void Test::testOrderManagement(){};

void Test::testMultipleStores(){};

void Test::runAllTests() {
    testUserAuthentication();
    testProductManagement();
    testStoreManagement();
    testCartManagement();
    testOrderManagement();
    testMultipleStores();
    std::cout << "All tests passed!" << std::endl;
}
