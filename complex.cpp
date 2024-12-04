#include <iostream>
#include <cmath>

using namespace std;

// Сдал

class ComplexNumber {

private:

    int real;
    int imag;
    float vector;
    static int complexCount;

public:

    ComplexNumber() {
        real = 1 + rand() % 20;
        imag = 1 + rand() % 20;
        vector = sqrt(real*real + imag*imag);
        complexCount++;
    }

    ComplexNumber(int r, int i) {
        this->imag = i;
        this->real = r;
        this->vector = sqrt(i*i + r*r);
        complexCount++;
    }

    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber& other) {
        return ComplexNumber(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    ComplexNumber operator/(const ComplexNumber& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cout << "Division by zero";
        }
        return ComplexNumber((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
    }

    bool operator<(const ComplexNumber& other) const {
        return getVector() < other.getVector();
    }

    bool operator>(const ComplexNumber& other) const {
        return getVector() > other.getVector();
    }

    void print() const {
        cout << real;
        if (imag >= 0) {
            cout << '+' << imag;
        } else {
            cout << imag;
        }
        cout << 'i';
    }

    void setComplexNumber(int r, int i) {
        real = r;
        imag = i;
        vector = sqrt(r*r + i*i);
    }

    int getReal() const { return real; }
    int getImag() const { return imag; }
    float getVector() const { return vector; }

    ComplexNumber(const ComplexNumber& p) {
        this->real = p.real;
        this->imag = p.imag;
        this->vector = p.vector;
        complexCount++;
    }

    static void CountPlus() {
        complexCount++;
    }

    static void CountMin() {
        complexCount++;
    }
    static int getComplexCount() {
        return complexCount;
    }

    ComplexNumber& operator++(int) {
        real++;
        return *this;
    }

    ComplexNumber& operator--(int) {
        real--;
        return *this;
    }

    ~ComplexNumber() {
        complexCount--;
    }
};

int ComplexNumber::complexCount = 0;

class TrigonometryComplexNumber : protected ComplexNumber {

private:
    float cos;
    float sin;

public:

    TrigonometryComplexNumber(int r, int i) : ComplexNumber(r, i) {
        this->cos = this->getReal() / this->getVector();
        this->sin = this->getImag() / this->getVector();
        this->CountPlus();
    }

    TrigonometryComplexNumber(float cos, float sin) : ComplexNumber() {
        this->cos = cos;
        this->sin = sin;
        this->CountPlus();;
    }

    float getCos() {
        return cos;
    }
    float getSin() {
        return sin;
    }

    void printTrigonometryForm() {
        cout << endl;
        cout << "Trigonometry form for ";
        this->print(); 
        cout << endl;
        cout << "Lenght of vector = " << this->getVector() << endl;
        cout << "Cos = " << cos << endl;
        cout << "Sin = " << sin << endl;
    }

    ~TrigonometryComplexNumber () {
        this->CountMin();
    }
};

class ComplexArray {

private:

    ComplexNumber* array;
    int count;

public:

    ComplexArray(ComplexNumber* arr, int count) {
        this->array = arr;
        this->count = count;
    }


    ComplexArray() {

        count = 1;
        array = new ComplexNumber[count];
        for (int i = 0; i < count; i++) {
            array[i] = ComplexNumber();
        }
    }

    int getCount() {
        return count;
    }

    void input() {
      
        cout << "Enter count: ";
        cin >> count;
        array = new ComplexNumber[count];

        for (int i = 0; i < count; i++) {
            int r, im;
            cout << "Enter real part: ";
            cin >> r;
            cout << "Enter imaginary part: ";
            cin >> im;
            array[i] = ComplexNumber(r, im);
        }
    }

    ComplexNumber sum() {

        int im = 0;
        int c = 0;

        for (int i = 0; i < count; i++) {
            im += array[i].getImag();
            c += array[i].getReal();
        }

        return ComplexNumber(c, im);
    }

    ComplexNumber max() {
        int max = -1000000;
        ComplexNumber res;
        for (int i = 0; i < count; i++) {
            if (max < array[i].getVector()) {
                max = array[i].getVector();
                res = array[i];
            }
        }

        return res;
    }

    ComplexNumber min() {
        int min = 1000000;
        ComplexNumber res;
        for (int i = 0; i < count; i++) {
            if (min > array[i].getVector()) {
                min = array[i].getVector();
                res = array[i];
            }
        }

        return res;
    }

    void bubbleSort() {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count - 1; j++) {
                if (array[j] > array[j + 1]) {
                    ComplexNumber temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    void insertionSort() {
        for (int i = 1; i < count; i++) {
            int j = i - 1;
            while (j >= 0 && array[j] > array[j + 1]) {
                ComplexNumber temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                j--;
            }
            
        }
    }

    void selectionSort() {
        int j = 0;
        for (int i = 0; i < count; i++) {
            j = i;
            for (int k = i; k < count; k++) {
                if (array[j] > array[k]) {
                    j = k;
                }
            }
            ComplexNumber temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            array[i].print();
            cout << "\n";
        }
    }

    ~ComplexArray() {
        delete[] array;
        cout << "\nDestructor\n";
    }
};



int main() {

    ComplexNumber c1(3, 4); 
    ComplexNumber c2(1, 2);
    ComplexNumber c3 = c1 * c2;
    ComplexNumber c4 = c1 / c2;
    ComplexNumber c5 = c1 - c2;
    ComplexNumber c6 = c1 + c2;

    cout << "Operator overloading: " << endl;

    bool res = c1 > c2;
    cout << "Overloading >: ";
    cout << res << endl;
    res = c1 < c2;
    cout << "Overloading <: ";
    cout << res << endl;

    c1.print();
    cout << " * ";
    c2.print();
    cout << " = ";
    c3.print();
    cout << endl; 

    c1.print();
    cout << " / ";
    c2.print();
    cout << " = ";
    c4.print();
    cout << endl; 

    c1.print();
    cout << " - ";
    c2.print();
    cout << " = ";
    c5.print();
    cout << endl; 

    c1.print();
    cout << " + ";
    c2.print();
    cout << " = ";
    c6.print();
    cout << endl; 

    for (int i = 0; i < 3; i++) {
        cout << "Array N" << i + 1 << endl;
        ComplexArray arr;
        arr.input();

        cout << "\nsum of array: ";
        arr.sum().print();
        cout << "\nsum++: ";
        arr.sum()++.print();
        cout << "\nsum--: ";
        arr.sum()--.print();
        cout << "\nmax: ";
        arr.max().print();
        cout << "\nmin: ";
        arr.min().print();

        cout << "\n without sort: \n";
        arr.print();
        cout << "\n after sort: \n";
        if (i == 0)
            arr.bubbleSort();
        if (i == 1) 
            arr.insertionSort();
        if (i == 2) {
            arr.selectionSort();
        }
        arr.print();

    }

    

    TrigonometryComplexNumber n(3, 5);
    n.printTrigonometryForm();

    cout << "Count complex number: " << ComplexNumber::getComplexCount();

    return 0;
}