#include "FoodDeliverySystem.h"
#include <iostream>
#include <limits>

bool FoodDeliverySystem::login(User& user) {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    return user.authenticate(password);
}

void FoodDeliverySystem::initializeStores() {
    GroceryStore* groceryStore1 = new GroceryStore("AFI Carrefour");
    groceryStore1->addProduct(new Product("Mar", 0.5, 100));
    groceryStore1->addProduct(new Product("Banana", 0.3, 150));
    groceryStore1->addProduct(new Product("Ciocolata", 0.3, 150));
    groceryStore1->addProduct(new Product("Lapte", 0.3, 150));

    GroceryStore* groceryStore2 = new GroceryStore("Coresi Auchan");
    groceryStore2->addProduct(new Product("Portocala", 0.6, 80));
    groceryStore2->addProduct(new Product("Mango", 4, 50));
    groceryStore2->addProduct(new Product("Avocado", 3, 50));
    groceryStore2->addProduct(new Product("Miere", 5, 50));
    groceryStore2->addProduct(new Product("Lapte Sana", 10, 50));
    groceryStore2->addProduct(new Product("Biscuiti Oreo", 10, 50));

    GroceryStore* groceryStore3 = new GroceryStore("Pizza Volla");
    groceryStore3->addProduct(new Product("Pizza Salami", 26, 80));
    groceryStore3->addProduct(new Product("Pizza Diavola", 28, 80));
    groceryStore3->addProduct(new Product("Pizza Margherita", 22, 80));
    groceryStore3->addProduct(new Product("Pizza Con Polo", 26, 80));
    groceryStore3->addProduct(new Product("Pizza Rustica", 26, 80));
    groceryStore3->addProduct(new Product("Pizza Quatro Stagioni", 26, 80));
    groceryStore3->addProduct(new Product("Pizza Quatro Formagi", 26, 80));

    GroceryStore* groceryStore4 = new GroceryStore("Pizza Hut");
    groceryStore4->addProduct(new Product("Pizza Salami", 26, 80));
    groceryStore4->addProduct(new Product("Pizza Diavola", 28, 80));
    groceryStore4->addProduct(new Product("Pizza Margherita", 22, 80));
    groceryStore4->addProduct(new Product("Pizza Con Polo", 26, 80));
    groceryStore4->addProduct(new Product("Pizza Rustica", 26, 80));
    groceryStore4->addProduct(new Product("Pizza Quatro Stagioni", 26, 80));
    groceryStore4->addProduct(new Product("Pizza Quatro Formagi", 26, 80));

    GroceryStore* groceryStore5 = new GroceryStore("Pizza Radu");
    groceryStore5->addProduct(new Product("Pizza Salami", 26, 80));
    groceryStore5->addProduct(new Product("Pizza Diavola", 28, 80));
    groceryStore5->addProduct(new Product("Pizza Margherita", 22, 80));
    groceryStore5->addProduct(new Product("Pizza Con Polo", 26, 80));
    groceryStore5->addProduct(new Product("Pizza Rustica", 26, 80));
    groceryStore5->addProduct(new Product("Pizza Quatro Stagioni", 26, 80));
    groceryStore5->addProduct(new Product("Pizza Quatro Formagi", 26, 80));

    stores.push_back(groceryStore1);
    stores.push_back(groceryStore2);
    stores.push_back(groceryStore3);
    stores.push_back(groceryStore4);
    stores.push_back(groceryStore5);
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
        std::cin.ignore();
        std::getline(std::cin, productName);
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
    std::cout << "Order confirmed for user " << order.getUser() << " with total price: (RON) " << cart.getTotalPrice() << std::endl;
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

