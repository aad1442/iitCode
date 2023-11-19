#include <stdio.h>
#include <math.h>

#define N 3 

void gaussianElimination(double A[N][2 * N])
{
    int i, j, k;

   
    for (i = 0; i < N; i++)
    {
       
        int p = i;
        while (A[p][i] == 0)
        {
            p++; 
            if (p == N)
            {
                printf("No unique solution exists\n");
                return;
            }
        }

       
        if (p != i)
        {
            for (j = 0; j < 2 * N; j++)
            {
                double temp = A[p][j];
                A[p][j] = A[i][j];
                A[i][j] = temp;
            }
        }

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
        {2, -1, 0},
        {-1, 2, -1},
        {0, -1, 2}};
    double operationalMat[N][2 * N];

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
