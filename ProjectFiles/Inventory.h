#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>

using namespace std;

class Inventory {
private:
    vector<Product> products;
    int nextId;

public:
    Inventory();
    void addProduct(string name, double price, int quantity);
    Product* findProduct(int id);
    void displayAll() const;
    int getProductCount() const;
    int getNextId() const;
};

#endif