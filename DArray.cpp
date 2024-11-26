#include <iostream>

// Лекция по проге N2

using namespace std;

class DArray {

private: 
    double *Array; // Ссылка на указатель
    int Count; // Текущее кол-во эл в массиве
    int MaxCount; // Макс кол-во эл в массиве

public:
    DArray() {
        this->Array = nullptr;
        this->Count = 0;
        this->MaxCount = 0;
    };

    DArray(int n) {
        this->Count = n;
        this->MaxCount = n * 2;
        this->Array = new double[this->MaxCount];
        for (int i = 0; i < this->Count; i++) { this->Array[i] = 0; }
    }

    DArray(int n, double value) {
        this->Count = n;
        this->MaxCount = n * 2;
        this->Array = new double[this->MaxCount];
        for (int i = 0; i < this->Count; i++) { this->Array[i] = value; }
    }

    DArray(int n, double *array) {
        this->Count = n;
        this->MaxCount = n * 2;
        this->Array = new double[this->MaxCount];
        for (int i = 0; i < this->Count; i++) { this->Array[i] = array[i]; }
    }

    ~DArray() {
        delete[] this->Array;
    }

    void print() {
        cout << "Array: ";
        for (int i = 0; i < this->Count; i++) { cout << this->Array[i] << " "; }
    }
    
};


int main() {

    DArray arr1(10, 2);
    arr1.print();
    return 0;
}