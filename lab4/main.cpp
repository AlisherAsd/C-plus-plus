#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class MyClass {
public: 
    T* Array; // Указатель на массив
    int Count;  // Текущий размер
    int MaxCount; // Максимально выделенная память

    MyClass() {
        this->Array = nullptr;
        this->Count = 0;
        this->MaxCount = 0;
    }

    // Конструктор для начальной инициализации
    MyClass(int n) : Count(n), MaxCount(n * 2) {
        this->Array = new T[MaxCount];
    }

    ~MyClass() {
        delete[] this->Array; // Освобождение памяти
    }

    MyClass& operator=(const MyClass& other) {
        if (this == &other) {
            return *this; // Самоприсваивание
        }
        delete[] Array; // Удаление прежнего массива
        this->Count = other.Count;
        Array = new T[Count];
        for (int i = 0; i < Count; i++) {
            Array[i] = other.Array[i];
        }
        return *this;
    }

    operator int() const {
        return Count;
    }

    MyClass(const MyClass& other) {
        this->Count = other.Count;
        Array = new T[Count];
        for (int i = 0; i < Count; i++) {
            Array[i] = other.Array[i];
        }
    }

    T& operator[](int index) {
        if (index < 0 || index >= Count) {
            cout << "Index out of range";
        }
        return Array[index];
    }

    void print() {
        for (int i = 0; i < Count; i++) { 
            cout << this->Array[i] << endl;
        }
    }

    void input() {
        cout << "Enter number of elements: ";
        cin >> Count;

        // Resize if needed
        if (Count > MaxCount) {
            delete[] Array; // Освобождение старой памяти
            MaxCount = Count * 2; // Увеличить максимальный размер
            Array = new T[MaxCount]; // Выделить новую память
        }

        for (int i = 0; i < Count; i++) {
            cout << "Array [" << i << "]: ";
            cin >> Array[i];  // Использует перегруженный оператор ввода
        }
    }
};

class ComplexNumber {
private:
    int real;
    int imag;
    float vector;

public:
    ComplexNumber() : real(0), imag(0), vector(0) {}

    ComplexNumber(int r, int i) : real(r), imag(i) {
        vector = sqrt(r * r + i * i);
    }

    // Определение операторов
    friend ostream& operator<<(ostream& os, const ComplexNumber& cn) {
        os << cn.real;
        if (cn.imag >= 0) {
            os << '+' << cn.imag << 'i';
        } else {
            os << cn.imag << 'i';
        }
        return os;
    }

    friend istream& operator>>(istream& is, ComplexNumber& cn) {
        cout << "Enter real part: ";
        is >> cn.real;
        cout << "Enter imaginary part: ";
        is >> cn.imag;
        cn.vector = sqrt(cn.real * cn.real + cn.imag * cn.imag); // Обновление вектора
        return is;
    }

    void print() const {
        cout << *this; // Использует оператор вывода
    }

   
};

int main() {
   
    MyClass<ComplexNumber> c;
    c.input();
    c.print();

    cout << "Override c2 = c: " << endl;
    MyClass<ComplexNumber> c2 = c;
    c2.print();
    cout << "Override c3(c): " << endl;
    MyClass<ComplexNumber> c3(c);
    c3.print();
    cout << "Override int(c): " << int(c) << endl;
    cout << "Override c[0]: " << c[0] << endl;



    MyClass<int> i;
    i.input();
    i.print();

    cout << "Override i2 = i: " << endl;
    MyClass<int> i2 = i;
    i2.print();
    cout << "Override i3(i): " << endl;
    MyClass<int> i3(i);
    i3.print();
    cout << "Override int(i): " << int(i) << endl;
    cout << "Override i[0]: " << i[0] << endl;


    MyClass<double> d;
    d.input();
    d.print();

    cout << "Override i2 = d: " << endl;
    MyClass<double> d2 = d;
    d2.print();
    cout << "Override d3(d): " << endl;
    MyClass<double> d3(d);
    d3.print();
    cout << "Override int(d): " << double(d) << endl;
    cout << "Override d[0]: " << d[0] << endl;
    
    
    return 0;
}