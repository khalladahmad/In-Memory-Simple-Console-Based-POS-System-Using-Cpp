#include "Customer.h"

Customer::Customer(string name, string phone, string email, string address)
    : name(name), phone(phone), email(email), address(address) {
}

void Customer::setDetails(string name, string phone, string email, string address) {
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

void Customer::display() const {
    cout << "\n=== Customer Details ===" << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    cout << "========================" << endl;
}

string Customer::getName() const { return name; }
string Customer::getPhone() const { return phone; }
string Customer::getEmail() const { return email; }
string Customer::getAddress() const { return address; }