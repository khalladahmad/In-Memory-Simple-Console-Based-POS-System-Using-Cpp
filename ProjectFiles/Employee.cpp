#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(string username, string password, string name)
    : username(username), password(password), name(name) {
}

bool Employee::authenticate(string inputUsername, string inputPassword) const {
    return (username == inputUsername && password == inputPassword);
}

string Employee::getName() const {
    return name;
}

string Employee::getUsername() const {
    return username;
}

void Employee::display() const {
    cout << "Employee: " << name << " (Username: " << username << ")" << endl;
}