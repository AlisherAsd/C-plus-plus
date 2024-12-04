#include <iostream>
#include <stdexcept> // Для std::runtime_error

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
        try {
            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col]();
            }
        } catch (const std::bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Parameterized constructor
    Matrix(int row, int col) : row(row), col(col) {
        if (row <= 0 || col <= 0) {
            throw std::invalid_argument("row or col must be greater than 0.");
        }
        try {
            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col]();
            }
        } catch (const std::bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Copy constructor
    Matrix(const Matrix &other) : row(other.row), col(other.col) {
        try {
            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col];
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        } catch (const std::bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            exit(EXIT_FAILURE);
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

        try {
            matrix = new double*[row];
            for (int i = 0; i < row; i++) {
                matrix[i] = new double[col];
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        } catch (const std::bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            exit(EXIT_FAILURE);
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
            throw std::invalid_argument("Matrices dimensions do not match.");
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
            throw std::out_of_range("Index out of range.");
        }
        return matrix[x][y];
    }

    // Input method
    void input() {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                cout << "Enter element for row " << i << " column " << j << ": ";
                try {
                    cin >> this->matrix[i][j];
                } catch (...) {
                    cerr << "Invalid input. Please enter a number." << endl;
                    j--; // Decrement j to repeat the input for the same element
                }
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
        Matrix one(2, 2);
        one.input();
        cout << "Matrix One:" << endl;
        one.print();

        Matrix two(2, 2);
        two.input();
        cout << "Matrix Two:" << endl;
        two.print();

        // if (one == two) {
        //     cout << "Matrices are equal." << endl;
        // }   

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

    } catch (const std::exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }

    return 0;
}