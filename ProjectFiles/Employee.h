#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee {
private:
    string username;
    string password;
    string name;

public:
    Employee(string username = "", string password = "", string name = "");

    bool authenticate(string inputUsername, string inputPassword) const;
    string getName() const;
    string getUsername() const;

    void display() const;
};

#endif