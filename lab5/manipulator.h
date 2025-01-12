#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <iostream>
#include <iomanip>

std::ostream& myManipulator(std::ostream& out, int width, char c) {
    out << std::fixed   
        << std::setfill(c)                // формат для вещественных чисел
        << std::setw(width);            // ширинв поля
    return out;
}

#endif
