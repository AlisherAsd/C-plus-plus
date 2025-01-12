#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

class Person {
    int id;
    char name[50];
    double value;

public:
    Person();
    Person(int, const char*, double);

    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend std::istream& operator>>(std::istream&, Person&);

    int getId() const;
    int getValue() const;

    // Перегрузка операторов сравнения
    bool operator<(const Person& other) const;
    bool operator>(const Person& other) const;
    bool operator==(const Person& other) const;
};

#endif
