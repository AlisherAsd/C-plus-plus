#include "person.cpp"
#include <fstream>
#include <iostream>

int find(const std::string& filename, int id) {
    Person obj;
    int pos = 0;

    std::ifstream inFile(filename, std::ios::binary); // Открываем файл для чтения
    if (!inFile) {
        std::cout << "Error opening file for reading.\n";
        return -1;
    }

    inFile.seekg(0, std::ios::beg); // Перемещаем указатель в начало файла
    while (inFile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        if (obj.getId() == id) {
            return pos; // Если нашли объект, возвращаем его позицию
        }
        ++pos;
    }
    return -1; // Если объект не найден
}

void del(const std::string& filename, int pos) {
    Person obj;
    Person objectsMass[100];
    int index = 0;
    // Открываем файл для чтения
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cout << "Error in prog4\n";
        return;
    }

    // Читаем все объекты из файла
    while (inFile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        objectsMass[index++] = obj;
    }
    inFile.close();

    // Открываем файл для записи (с флагом trunc, чтобы перезаписать его)
    std::ofstream outFile(filename, std::ios::binary | std::ios::trunc);
    if (!outFile) {
        std::cout << "Error in prog4\n";
        return;
    }

    // Записываем все объекты, кроме того, который нужно удалить
    for (int i = 0; i < index; ++i) {
        if (static_cast<int>(i) != pos) {
            outFile.write(reinterpret_cast<const char*>(&objectsMass[i]), sizeof(objectsMass[i]));
        }
    }
    outFile.close();

    std::cout << "Object at position " << pos << " deleted.\n";
}

int main() {
    std::string filename = "data.bin";

    int idToDelete1 = 1;
    int idToDelete2 = 2;

    // Находим позицию объекта с ID 1
    int pos1 = find(filename, idToDelete1);
    if (pos1 != -1) {
        del(filename, pos1); // Удаляем объект с ID 1
    } else {
        std::cout << "Object with ID " << idToDelete1 << " not found.\n";
    }

    // Находим позицию объекта с ID 2
    int pos2 = find(filename, idToDelete2);
    if (pos2 != -1) {
        del(filename, pos2); // Удаляем объект с ID 2
    } else {
        std::cout << "Object with ID " << idToDelete2 << " not found.\n";
    }

    return 0;
}