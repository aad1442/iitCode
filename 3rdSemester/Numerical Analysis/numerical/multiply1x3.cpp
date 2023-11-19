#include <iostream>

int main() {
    // Define matrices A and B
    int A[1][3] = {{2, 3, 4}};
    int B[3][1] = {{1}, {5}, {2}};

    // Result matrix C initialized to zero
    int C[1][1] = {{0}};

    // Perform matrix multiplication
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display the result
    std::cout << "Result of matrix multiplication (1x3 * 3x1):\n";
    std::cout << C[0][0] << std::endl;

    return 0;
}
