#include <iostream>
#include <stdexcept> 
#include <string>

using namespace std;

const int defaultMaxSize = 10;



class MatrixException : public exception {
    string message;
    
public:
    explicit MatrixException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};



class Matrix {

private:
    bool isEqual(const Matrix& other) const {
        if (this->col != other.col || this->row != other.row) return false;

        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool sizeEqual(const Matrix& other) const {
        if (this->col != other.col || this->row != other.row) return false;
        return true;
    }

public:
    double **matrix;
    int row;
    int col;

    // Default constructor
    Matrix() : row(defaultMaxSize), col(defaultMaxSize) {
        
            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col]();
            }
       
    }

    // Parameterized constructor
    Matrix(int row, int col) : row(row), col(col) {
        if (row <= 0 || col <= 0) {
            throw MatrixException("Максимальный размер матрицы должен быть положительным");
        }
            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col]();
            }
     
    }

    // Copy constructor
    Matrix(const Matrix &other) : row(other.row), col(other.col) {
            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col];
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
       
    }

    Matrix& operator=(const Matrix &other) {
        if (this == &other) return *this;

        for (int i = 0; i < row; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        row = other.row;
        col = other.col;

            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col];
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
       

        return *this;
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Equality operator
    bool operator==(const Matrix& other) const {
        return isEqual(other);
    }

    // Subtraction operator
    Matrix operator-(const Matrix& other) const {
        if (!sizeEqual(other)) {
            throw MatrixException("Матрицы имеют разный размер");
        }

        Matrix result(row, col);
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        
        return result; // Calls copy constructor
    }

    Matrix operator-(double el) const {
        Matrix result(row, col);
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                result.matrix[i][j] =  matrix[i][j] - el;
            }
        }
        return result;
    }

    double operator () (int x, int y) const {
        if (x < 0 || x >= row || y < 0 || y >= col) {
            throw MatrixException("Выход за границы индекса");
        }
        return matrix[x][y];
    }

    // Input method
    void input() {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                cout << "Enter element for row " << i << " column " << j << ": ";
                    cin >> this->matrix[i][j];
                
            }
        }
    }

    void AutoInput() {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                this->matrix[i][j] = 1;
                
            }
        }
    }

    // Print method
    void print() const {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Accessor methods
    int getCol() const {
        return col;
    }

    int getRow() const {
        return row;
    }
};

int main() {
    try {
        int x, y;
        cout << "Введите размер матрицы 1" << endl;
        cout << "Введите х >= 0: ";
        cin >> x;
        cout << "Введите y >= 0: ";
        cin >> y;

        Matrix one(x, y);
        one.AutoInput();
        cout << "Matrix One:" << endl;
        one.print();

        cout << "Введите размер матрицы 1 (друго1 для проверки равенства размера)" << endl;
        cout << "Введите х >= 0: ";
        cin >> x;
        cout << "Введите y >= 0: ";
        cin >> y;
        Matrix two(x, y);
        two.AutoInput();
        cout << "Matrix Two:" << endl;
        two.print();

        // Ошибка при сравнении размера матриц
        Matrix rasnostmatrix = one - two;
        cout << "Result of rasnost matrix:" << endl;

        // Ошибка при выходе за границу
        cout << "Введите индексы элемента" << endl;
        cout << "Введите х >= 0: ";
        cin >> x;
        cout << "Введите y >= 0: ";
        cin >> y;
        cout << "\n matrix(" << x << ", " << y << "): " << one(x, y);

    } catch (const MatrixException& ex) {
        cout << "Произошла ошибка: " << ex.what() << endl;
    }
    catch (const exception& ex) {
        cout << "Произошла неизвестная ошибка: " << ex.what() << endl;
    }
    cout << "\nПрограмма завершена." << endl;

    return 0;
}