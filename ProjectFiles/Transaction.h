#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Product.h"
#include "Customer.h"
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class TransactionItem {
private:
    int productId;
    string productName;
    int quantity;
    double price;
    double subtotal;

public:
    TransactionItem(int productId, string productName, int quantity, double price);
    void calculateSubtotal();
    void display() const;
    double getSubtotal() const;
};

class Transaction {
private:
    int id;
    string timestamp;
    vector<TransactionItem> items;
    double total;
    Customer customer;
    string employeeName;

public:
    Transaction(int id = 0, string employeeName = "");
    void setTimestamp();
    void addItem(int productId, string productName, int quantity, double price);
    void setCustomer(Customer cust);
    void calculateTotal();
    void display() const;
    double getTotal() const;
    int getId() const;
    Customer getCustomer() const;
};

#endif