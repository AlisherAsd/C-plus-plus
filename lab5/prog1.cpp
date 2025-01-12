#include "person.cpp"
#include <fstream>

int main() {
    Person objectsMass[100];
    int index = 0;
    int n;
    std::cout << "number of objects: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Person obj;
        std::cin >> obj;
        objectsMass[index++] = obj;
    }

    std::ofstream outFile("data.bin", std::ios::binary);
    
    for (int i = 0; i < index; i++){
        outFile.write(reinterpret_cast<const char*>(&objectsMass[i]), sizeof(objectsMass[i]));
    }

    outFile.close();


    std::ifstream inFile("data.bin", std::ios::binary);

    if (!inFile) {
        std::cout << "Error in prog1\n";
        return 1;
    }

    inFile.seekg(0, std::ios::end); //указатель на конец файла
    std::streamsize fileSize = inFile.tellg(); //размер файла
    inFile.close();

    size_t objectSize = sizeof(Person);
    int objectCount = fileSize / objectSize; //количество объектов

    std::cout << "file contains " << objectCount << " objects\n";
    return 0;
}
