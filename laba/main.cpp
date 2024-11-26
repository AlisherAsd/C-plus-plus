#include <iostream>
#include <cstring>
#include "class/Person.h"
#include "class/Employee.h"
#include "class/Worker.h"
#include "class/Engineer.h"

// Лабoраторная работа В-2

using namespace std;


Person* Person::begin = nullptr;
int Person::count = 0;



int main() {

    Employee Alex("Alex", 18, "bakalavr");
    Worker Alisher("Alisher", 25, "web developer");
    Engineer Jakson("Jakson", 40, 4);

    // Реализация добавление в список с помощью метода add
    Alex.add();
    Alisher.add();
    Jakson.add();

    // Реализация добавление в список при инициализации объекта
    Employee Employee1;
    Worker Worker1;
    Engineer Engineer1;

    Person::print();
    Person::getCount();

    return 0;
}

