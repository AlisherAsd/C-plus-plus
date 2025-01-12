#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <fstream>

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

};

#endif
