#include <stdio.h>
#include <math.h>

#define N 3 // Define the number of equations

void gaussianElimination(double A[N][2 * N])
{
    int i, j, k;

    // Elimination process
    for (i = 0; i < N; i++)
    {
        // Step 2: Find the pivot row (p)
        int p = i;
        while (A[p][i] == 0)
        {
            p++; // Move to the next row if pivot is zero
            if (p == N)
            {
                printf("No unique solution exists\n");
                return;
            }
        }

        // Step 3: Swap rows if necessary
        if (p != i)
        {
            for (j = 0; j < 2 * N; j++)
            {
                double temp = A[p][j];
                A[p][j] = A[i][j];
                A[i][j] = temp;
            }
        }

        // Step 4: Perform elimination for each row below i
        for (j = 0; j < N; j++)
        {
            if (j != i)
            {
                double m = A[j][i] / A[i][i];
                for (k = i; k < 2 * N; k++)
                {
                    A[j][k] -= m * A[i][k];
                }
            }
        }
    }

    // Normalize the rows(make the diagonal 1) to get the inverse matrix
    for (i = 0; i < N; i++)
    {
        double pivot = A[i][i];
        for (j = 0; j < 2 * N; j++)
        {
            A[i][j] /= pivot;
        }
    }
}
int main()
{
    double A[N][N] = {
        {4, 1, 1},
        {2, 5, 2},
        {1, 2, 4}};
    double operationalMat[N][2 * N];

    // Initialize operationalMat with the original matrix A augmented with the identity matrix
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            operationalMat[row][col] = A[row][col];
        }
        for (int col = N; col < 2 * N; col++)
        {
            if (col - N == row)
            {
                operationalMat[row][col] = 1.0;
            }
            else
            {
                operationalMat[row][col] = 0.0;
            }
        }
    }

    gaussianElimination(operationalMat);

    printf("Inverse matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = N; j < 2 * N; j++)
        {
            printf("%0.2lf   ", operationalMat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
