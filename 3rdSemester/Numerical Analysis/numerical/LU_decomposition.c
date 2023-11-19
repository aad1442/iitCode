#include <stdio.h>
#define N 3
double result[N][N];
double upper[N][N];
double lower[N][N]; // identity mat with lower tri part having m values
void print(double mat[N][N])
{
    for (int row = 0; row < N; row++)
    {
        printf("|");
        for (int col = 0; col < N; col++)
        {
            printf("%.2lf     ", mat[row][col]);
        }
        printf("|");
        printf("\n");
    }
}
void lowerTriElimination(double A[N][N], double lower[N][N])
{
    int i, j, k;
    for (i = 0; i < N - 1; i++)
    {
        int p = i;
        while (A[p][i] == 0)
        {
            p++;
        }
        if (p != i)
        {
            for (j = 0; j < N; j++)
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

        for (j = i + 1; j < N; j++)
        {
            double m = A[j][i] / A[i][i];
            lower[j][i] = m;
            for (k = i; k < N; k++)
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
}

void multiplication(double matA[3][3], double matB[3][3], int row1, int row2, int col2, double result[N][N])
{

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < row2; k++)
            {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}
int main()
{
    int flag = 0;
    double matrix[3][3] = {
        {4, 1, 1},
        {2, 5, 2},
        {1, 2, 4}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            upper[i][j] = matrix[i][j];
            if (i == j)
                lower[i][j] = 1;
            else
                lower[i][j] = 0;
        }
    }

    printf("\n");
    lowerTriElimination(upper, lower);
    printf("matrix L\n");
    print(lower);
    printf("\nmatrix U\n");
    print(upper);
    multiplication(lower, upper, 3, 3, 3, result);
    printf("\nmatrix LU:\n");
    print(result);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (result[i][j] != matrix[i][j])
            {
                flag = 1;
            }
        }
    }
    if (flag == 1)
        printf("Not perfectly decomposed");
    else
        printf("perfectly decomposed");
}