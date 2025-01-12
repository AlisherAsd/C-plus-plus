#include "person.cpp"
#include <fstream>
#include <iostream>

void repl(std::fstream& file, int pos, const Person& newObj) {
    file.seekp(pos * sizeof(Person), std::ios::beg);
    file.write(reinterpret_cast<const char*>(&newObj), sizeof(newObj));
}

int find(std::fstream& file, int id) {
    Person obj;
    int pos = 0;

    file.seekg(0, std::ios::beg);
    while (file.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        if (obj.getId() == id) {
            return pos;
        }
        ++pos;
    }
    return -1;
}

int main() {
    std::fstream file("data.bin", std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Error in prog5\n";
        return 1;
    }

    int idToReplace = 2;
    int pos = find(file, idToReplace);

    if (pos != -1) {
        Person newObj(2, "Updated person", 80.0);
        repl(file, pos, newObj);
    } else {
        std::cout << "Object with ID " << idToReplace << " not found.\n";
    }

    file.close();

    return 0;
}