#include "person.cpp"
#include <fstream>
#include <iostream>

int main() {
    Person obj1(1, "Man", 100.5);
    Person obj2(2, "Woman", 50.75);

    std::ofstream outFile("data.bin", std::ios::binary | std::ios::app);
    if (!outFile) {
        std::cout << "Error in prog3\n";
        return 1;
    }

    outFile.write(reinterpret_cast<const char*>(&obj1), sizeof(obj1));
    outFile.write(reinterpret_cast<const char*>(&obj2), sizeof(obj2));

    outFile.close();

    return 0;
}