#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Person {

protected:
    string name;
    int age;
    static Person* begin; // указатель на начало списка
    static int count;
    Person* next;

public:

    Person() {
        this->add(); 
        count++;
    };
    Person(string name, int age) {
        this->name = name;
        this->age = age;
        count++;
    };
    Person(const Person&) {};
    void show() {};
    ~Person() {};
    static void print() {
        Person* current = begin;
        while (current) {
            current->show();
            current = current->next;
        }
    };

    static void getCount() {
        cout << "Total count: " << count << endl;
    }

    void add() {
        next = begin;
        begin = this;
    }
};