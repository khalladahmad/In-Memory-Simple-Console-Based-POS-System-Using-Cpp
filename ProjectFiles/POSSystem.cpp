#include "POSSystem.h"
#include <iostream>
#include <limits>

using namespace std;

POSSystem::POSSystem() : nextTransactionId(1) {}

void POSSystem::initializeEmployees() {
    // Pre-defined employees for demo
    employees.push_back(Employee("admin", "admin123", "Manager John"));
    employees.push_back(Employee("cashier1", "cash123", "Cashier Alice"));
    employees.push_back(Employee("cashier2", "cash456", "Cashier Bob"));
}

bool POSSystem::login() {
    string username, password;

    cout << "\n=== Employee Login ===" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (const auto& employee : employees) {
        if (employee.authenticate(username, password)) {
            currentEmployee = employee;
            cout << "\nLogin successful! Welcome " << employee.getName() << "!" << endl;
            return true;
        }
    }

    cout << "Invalid credentials! Please try again." << endl;
    return false;
}

Customer POSSystem::getCustomerDetails() {
    Customer customer;
    string name, phone, email, address;

    cout << "\n=== Enter Customer Details ===" << endl;
    cout << "Customer Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Phone Number: ";
    getline(cin, phone);

    cout << "Email: ";
    getline(cin, email);

    cout << "Address: ";
    getline(cin, address);

    customer.setDetails(name, phone, email, address);
    return customer;
}

void POSSystem::employeeMenu() {
    int choice;

    do {
        cout << "\n=== Employee Menu ===" << endl;
        cout << "Logged in as: " << currentEmployee.getName() << endl;
        cout << "1. Add New Product" << endl;
        cout << "2. Create Bill for Customer" << endl;
        cout << "3. View Inventory" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            createBill();
            break;
        case 3:
            displayInventory();
            break;
        case 4:
            displayTransactionHistory();
            break;
        case 5:
            cout << "Logging out..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 5);
}

void POSSystem::addProduct() {
    string name;
    double price;
    int quantity;

    cout << "\n=== Add New Product ===" << endl;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter product price: ";
    cin >> price;

    cout << "Enter product quantity: ";
    cin >> quantity;

    inventory.addProduct(name, price, quantity);
}

void POSSystem::createBill() {
    Transaction transaction(nextTransactionId, currentEmployee.getName());
    Customer customer = getCustomerDetails();
    transaction.setCustomer(customer);

    int choice;

    do {
        cout << "\n=== Current Transaction ===" << endl;
        customer.display();
        cout << "1. Add item to transaction" << endl;
        cout << "2. Complete transaction" << endl;
        cout << "3. Cancel transaction" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int productId, quantity;

            displayInventory();
            cout << "Enter product ID: ";
            cin >> productId;

            cout << "Enter quantity: ";
            cin >> quantity;

            Product* product = inventory.findProduct(productId);
            if (product) {
                if (product->getQuantity() >= quantity) {
                    transaction.addItem(productId, product->getName(), quantity, product->getPrice());
                    product->updateQuantity(-quantity);
                    cout << "Item added to transaction." << endl;
                }
                else {
                    cout << "Not enough stock! Available: " << product->getQuantity() << endl;
                }
            }
            else {
                cout << "Product not found!" << endl;
            }
        }

    } while (choice != 2 && choice != 3);

    if (choice == 2) {
        transaction.display();
        transactions.push_back(transaction);
        cout << "Transaction completed successfully!" << endl;
        nextTransactionId++;
    }
    else {
        cout << "Transaction cancelled." << endl;
    }
}

void POSSystem::displayTransactionHistory() const {
    cout << "\n=== Transaction History ===" << endl;
    if (transactions.empty()) {
        cout << "No transactions yet." << endl;
        return;
    }

    for (const auto& transaction : transactions) {
        transaction.display();
    }
}

void POSSystem::displayInventory() const {
    inventory.displayAll();
}

void POSSystem::run() {
    initializeEmployees();
    int choice;

    do {
        cout << "\n=== POS System Main Menu ===" << endl;
        cout << "1. Employee Login" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (login()) {
                employeeMenu();
            }
            break;
        case 2:
            cout << "Thank you for using POS System!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 2);
}