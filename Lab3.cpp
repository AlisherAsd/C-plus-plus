#include <iostream>

using namespace std;

const int defaultMaxSize = 10;

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

public:
    double** matrix;
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
            cout << "row or col <= 0." << endl;
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
        if (!isEqual(other)) {
            cout << "Matrxs not equal." << endl;
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
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                if (i == x && j == y) 
                    return matrix[x][y];
            }
        }
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
    Matrix one(2, 2);
    one.input();
    cout << "Matrix One:" << endl;
    one.print();

    Matrix two(2, 2);
    two.input();
    cout << "Matrix Two:" << endl;
    two.print();

    if (one == two) {
        cout << "Matrices are equal." << endl;
    }   


    Matrix rasnostmatrix = one - two;
    cout << "Result of rasnost matrix:" << endl;
    rasnostmatrix.print();

    double ras;
    cout << "Enter chislo for rasnost: ";
    cin >> ras;
    Matrix rasnostchisel = rasnostmatrix - ras;
    cout << "\n Result of rasnost chisel:" << endl;
    rasnostchisel.print();

    int x, y;
    cout << "enter x: ";
    cin >> x;
    cout << "enter y: ";
    cin >> y;

    cout << "\n matrix(" << x << ", " << y << "): " << rasnostchisel(x, y);

    cout << "\n override =: " << endl;
    Matrix ravno = rasnostchisel;
    ravno.print();
   
    return 0;
}
