#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

using namespace std;

class Customer {
private:
    string name;
    string phone;
    string email;
    string address;

public:
    Customer(string name = "", string phone = "", string email = "", string address = "");

    void setDetails(string name, string phone, string email, string address);
    void display() const;

    string getName() const;
    string getPhone() const;
    string getEmail() const;
    string getAddress() const;
};

#endif