#include <stdio.h>
#include <math.h>

#define N 3 // Define the number of equations

void gaussianElimination(double A[N][N + 1], double X[N])
{
    int i, j, k;

    // Elimination process
    for (i = 0; i < N - 1; i++)
    {
        // Step 2: Find the pivot row (p)
        int p = i;
        while (A[p][i] == 0)
        {

            p++; // doing it to check if(p!=i) + swaping it with the next row
        }
        // Step 3: Swap rows if necessary
        if (p != i)
        {
            for (j = 0; j <= N; j++) // col will iterate <=N cuz last col was for ans
            {
                double temp = A[p][j];
                A[p][j] = A[i][j];
                A[i][j] = temp;
            }
        }

        if (p == N)
        {
            printf("No unique solution exists\n");
            return;
        }

        // Step 4: Perform elimination for each row below i
        for (j = i + 1; j < N; j++)
        {
            double m = A[j][i] / A[i][i];
            for (k = i; k <= N; k++)
            {
                A[j][k] -= m * A[i][k];
            }
        }
    }

    if (A[N - 1][N - 1] == 0) // A[1][1]=0
    {
        printf("No unique solution exists\n");
        return;
    }

    // Backward substitution
    for (i = 0; i < N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            printf("%0.2lf  ", A[i][j]);
        }
        printf("\n");
    }
    X[N - 1] = (A[N - 1][N]) / (A[N - 1][N - 1]);
    for (i = N - 2; i >= 0; i--)
    {
        double sum = A[i][N];
        for (j = i + 1; j < N; j++)
        {
            sum -= A[i][j] * X[j];
        }
        X[i] = sum / A[i][i];
    }

    printf("Solution:\n");
    for (i = 0; i < N; i++)
    {
        printf("x%d = %0.2lf\n", i + 1, X[i]);
    }

    double det = 1; // det is consisted of multiplying diagonal elements
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {

                det *= A[i][j];
            }
        }
    }
    printf("determinent: %0.2lf ", det);
}

int main()
{
    double A[N][N + 1] = {
        {4, 1, 1, 8},
        {2, 5, 2, 3},
        {1, 2, 4, 11}

    };
    double X[N];

    gaussianElimination(A, X);

    return 0;
}
