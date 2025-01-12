#include "person.h"
#include <cstring>

Person::Person() : id(0), value(0.0) {
    strcpy(name, "");
}

Person::Person(int id, const char* name, double value) : id(id), value(value) {
    strncpy(this->name, name, sizeof(this->name));
}
//запись
std::ostream& operator<<(std::ostream& out, const Person& obj) {
    out << "ID: " << obj.id << ", Name: " << obj.name << ", Value: " << obj.value;
    return out;
}

std::istream& operator>>(std::istream& in, Person& obj) {
    std::cout << "Enter ID: ";
    in >> obj.id;
    in.ignore();
    std::cout << "Enter Name: ";
    in.getline(obj.name, sizeof(obj.name));
    std::cout << "Enter Value: ";
    in >> obj.value;
    return in;
}

int Person::getId() const {
    return id;
}
