#include "person.h"

Person::Person() : id(0), value(0.0) {
    strcpy(name, "");
}

Person::Person(int id, const char* name, double value) : id(id), value(value) {
    strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0';
}

// Запись
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

int Person::getValue() const {
    return value;
}


// Перегрузка операторов сравнения
bool Person::operator<(const Person& other) const {
    return this->value < other.value;
}

bool Person::operator>(const Person& other) const {
    return this->value > other.value;
}

bool Person::operator==(const Person& other) const {
    return this->id == other.id && strcmp(this->name, other.name) == 0 && this->value == other.value;
}
