#pragma once

#include <iostream>
#include <cstring>
#include "Person.h"


class Engineer : virtual public Person {

private:
    int rank; // Разряд

public:

    Engineer() : Person() {
        this->name = "Engineer";
        this->rank = 1;
        this->age = 38;
   
    };
    Engineer(string name, int age, int rank) : Person(name, age) {
        this->rank = rank;
    };
    void show() override {
        cout << "rank: " << rank << endl;
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << endl;
    };
    ~Engineer() {};
};

