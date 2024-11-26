#pragma once

#include <iostream>
#include <cstring>
#include "Person.h"


class Worker : virtual public Person {

private:
    string work; // Работа

public:

    Worker() : Person() {
        this->name = "Worker";
        this->work = "work";
        this->age = 28;
        
    };
    Worker(string name, int age, string work) : Person(name, age) {
        this->work = work;
    };
    void show() override {
        cout << "work: " << work << endl;
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << endl;
    };
    ~Worker() {};
};