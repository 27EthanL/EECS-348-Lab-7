#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

// Lab was finished before Friday's session
// So input is from file instead of user as stated in the beginning to the session

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin(){
    string line;
    int num;
    static int count;
    vector<int> numbers;

    ifstream file("matrix-data.txt");

    for (int i = 0; i < SIZE*2; ++i) {
        if (getline (file, line)) {
            stringstream ss(line);
            
            while (ss >> num) {
                numbers.push_back(num);
            }
        }
    }

    int arr[(SIZE*SIZE)*2];
    for (int i = 0; i < numbers.size(); ++i) {
        arr[i] = numbers[i];
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            data[i][j] = arr[count];
            count++;
        }
    }
  }

  // 2. Display a matrix
  void display() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() {
    int main = 0;
    int secondary = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                main += data[i][j];
            }

            if ((i + j) == (SIZE - 1)) {
                secondary += data[i][j];
            }
        }
    }

    return main + secondary;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    for (int i = 0; i < SIZE; i++) {
        int number = data[row1][i];
        data[row1][i] = data[row2][i];
        data[row2][i] = number;
    }
  }
};

int main() {
    // Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << endl;

    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl << endl;

    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}