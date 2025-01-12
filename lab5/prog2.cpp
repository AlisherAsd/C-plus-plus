#include "person.cpp"
#include "manipulator.h"
#include <fstream>
#include <iostream>

int main() {
    std::ifstream inFile("data.bin", std::ios::binary);
    if (!inFile) {
        std::cout << "Error in prog2\n";
        return 1;
    }

    inFile.seekg(0, std::ios::end);
    std::streamsize fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    size_t objectSize = sizeof(Person);

    int objectCount = fileSize / objectSize;
    std::cout << "file contains " << objectCount << " objects.\n";
    std::cout << "weight of all bytes " << fileSize << "\n";


///////////////// 
    Person objectsMass[100];
    int index = 0;
    Person obj;
    while (inFile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        objectsMass[index++] = obj;
    }

    inFile.close();

    for (int i = 0; i < index; i++){
        myManipulator(std::cout, 15, '-') << objectsMass[i] << std::endl;
    }
    return 0;
}