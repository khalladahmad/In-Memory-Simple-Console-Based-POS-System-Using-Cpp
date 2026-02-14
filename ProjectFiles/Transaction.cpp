#include "Transaction.h"
#include <iostream>
#include <iomanip>

using namespace std;

// TransactionItem Implementation
TransactionItem::TransactionItem(int productId, string productName, int quantity, double price)
    : productId(productId), productName(productName), quantity(quantity), price(price), subtotal(0.0) {
    calculateSubtotal();
}

void TransactionItem::calculateSubtotal() {
    subtotal = price * quantity;
}

void TransactionItem::display() const {
    cout << "  " << productName << " x " << quantity
        << " = $" << fixed << setprecision(2) << subtotal << endl;
}

double TransactionItem::getSubtotal() const { return subtotal; }

// Transaction Implementation
Transaction::Transaction(int id, string employeeName)
    : id(id), total(0.0), employeeName(employeeName) {
    setTimestamp();
}

void Transaction::setTimestamp() {
    time_t now = time(0);
    timestamp = ctime(&now);
    if (!timestamp.empty() && timestamp[timestamp.length() - 1] == '\n') {
        timestamp.erase(timestamp.length() - 1);
    }
}

void Transaction::addItem(int productId, string productName, int quantity, double price) {
    items.push_back(TransactionItem(productId, productName, quantity, price));
    calculateTotal();
}

void Transaction::setCustomer(Customer cust) {
    customer = cust;
}

void Transaction::calculateTotal() {
    total = 0.0;
    for (const auto& item : items) {
        total += item.getSubtotal();
    }
}

void Transaction::display() const {
    cout << "\n=== Transaction #" << id << " ===" << endl;
    cout << "Time: " << timestamp << endl;
    cout << "Employee: " << employeeName << endl;

    customer.display();

    cout << "Items:" << endl;
    for (const auto& item : items) {
        item.display();
    }

    cout << "Total: $" << fixed << setprecision(2) << total << endl;
    cout << "=========================" << endl;
}

double Transaction::getTotal() const { return total; }
int Transaction::getId() const { return id; }
Customer Transaction::getCustomer() const { return customer; }