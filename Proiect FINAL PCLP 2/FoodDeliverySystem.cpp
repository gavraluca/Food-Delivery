#include "FoodDeliverySystem.h"
#include <iostream>

bool FoodDeliverySystem::login(User& user) {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    return user.authenticate(password);
}

void FoodDeliverySystem::initializeStores() {
    GroceryStore* groceryStore1 = new GroceryStore("Local Grocery 1");
    groceryStore1->addProduct(new Product("Apple", 0.5, 100));
    groceryStore1->addProduct(new Product("Banana", 0.3, 150));

    GroceryStore* groceryStore2 = new GroceryStore("Local Grocery 2");
    groceryStore2->addProduct(new Product("Orange", 0.6, 80));
    groceryStore2->addProduct(new Product("Mango", 1.2, 50));

    stores.push_back(groceryStore1);
    stores.push_back(groceryStore2);
}

Store* FoodDeliverySystem::chooseStore() {
    std::cout << "Available stores:" << std::endl;
    for (size_t i = 0; i < stores.size(); ++i) {
        std::cout << i + 1 << ". " << stores[i]->getName() << std::endl;
    }

    int choice;
    std::cout << "Choose a store by number: ";
    std::cin >> choice;

    if (choice > 0 && choice <= stores.size()) {
        return stores[choice - 1];
    }

    return nullptr;
}

void FoodDeliverySystem::shop(Store* store, Cart& cart) {
    std::string productName;
    int quantity;

    while (true) {
        std::cout << "Enter product name to add to cart (or 'done' to finish): ";
        std::cin >> productName;
        if (productName == "done") {
            break;
        }

        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        Product* product = store->getProduct(productName);
        if (product && product->getStock() >= quantity) {
            product->reduceStock(quantity);
            for (int i = 0; i < quantity; ++i) {
                cart.addProduct(product);
            }
        } else {
            std::cout << "Product not available or insufficient stock." << std::endl;
        }
    }
}

void FoodDeliverySystem::placeOrder(User& user, Cart& cart) {
    Order order(user.getUsername(), cart);
    order.confirmOrder();
    std::cout << "Order confirmed for user " << order.getUser() << " with total price: $" << cart.getTotalPrice() << std::endl;
}

void FoodDeliverySystem::run() {
    User user("Luca", "abcd1234");

    if (!login(user)) {
        std::cout << "Authentication failed!" << std::endl;
        return;
    }

    initializeStores();

    Store* chosenStore = chooseStore();
    if (!chosenStore) {
        std::cout << "Invalid store selection!" << std::endl;
        return;
    }

    Cart cart;
    shop(chosenStore, cart);

    placeOrder(user, cart);

    for (Store* store : stores) {
        delete store;
    }
}

