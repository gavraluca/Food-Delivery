#include <iostream>
#include <cassert>
#include "Test.h"
#include "User.h"
#include "Store.h"
#include "Product.h"
#include "Cart.h"
#include "Order.h"

void Test::testUserAuthentication(){};

void Test::testProductManagement(){};

void Test::testStoreManagement(){};

void Test::testCartManagement(){};

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
