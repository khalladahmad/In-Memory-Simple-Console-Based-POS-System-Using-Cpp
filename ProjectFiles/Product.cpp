#include "Product.h"

Product::Product(int id, string name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {
}

// Getters
int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

// Setters
void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setQuantity(int newQuantity) { quantity = newQuantity; }

void Product::updateQuantity(int amount) {
    quantity += amount;
    if (quantity < 0) quantity = 0;
}

void Product::display() const {
    cout << "ID: " << id << ", Name: " << name
        << ", Price: $" << fixed << setprecision(2) << price
        << ", Quantity: " << quantity << endl;
}