#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product(int id = 0, string name = "", double price = 0.0, int quantity = 0);

    // Getters
    int getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    void updateQuantity(int amount);

    void display() const;
};

#endif#pragma once
