#ifndef POSSYSTEM_H
#define POSSYSTEM_H

#include "Inventory.h"
#include "Transaction.h"
#include "Employee.h"
#include "Customer.h"
#include <vector>

using namespace std;

class POSSystem {
private:
    Inventory inventory;
    vector<Transaction> transactions;
    vector<Employee> employees;
    int nextTransactionId;
    Employee currentEmployee;

    bool login();
    Customer getCustomerDetails();
    void employeeMenu();
    void addProduct();
    void createBill();
    void displayTransactionHistory() const;
    void displayInventory() const;

public:
    POSSystem();
    void initializeEmployees();
    void run();
};

#endif