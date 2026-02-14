#include "Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory() : nextId(1) {}

void Inventory::addProduct(string name, double price, int quantity) {
    products.push_back(Product(nextId, name, price, quantity));
    nextId++; // Increment ID after adding
    cout << "Product added successfully! (ID: " << nextId - 1 << ")" << endl;
}

Product* Inventory::findProduct(int id) {
    for (auto& product : products) {
        if (product.getId() == id) {
            return &product;
        }
    }
    return nullptr;
}

void Inventory::displayAll() const {
    cout << "\n=== Inventory ===" << endl;
    if (products.empty()) {
        cout << "No products in inventory." << endl;
        return;
    }

    for (const auto& product : products) {
        product.display();
    }
    cout << "=================" << endl;
}

int Inventory::getProductCount() const { return products.size(); }
int Inventory::getNextId() const { return nextId; }