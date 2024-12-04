#pragma once

#include <iostream>
#include <cstring>
#include "Person.h"

using namespace std;

class Employee : virtual public Person {

private:
    string degree; // Ученая степень

public:

    Employee() : Person() {
        this->name = "Employee";
        this->degree = "degree";
        this->age = 18;
       
    };
    Employee(string name, int age, string degree) : Person(name, age) {
        this->degree = degree;
    };
    void show() override {
        cout << "degree: " << degree << endl;
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << endl;
    };
    ~Employee() {};
};