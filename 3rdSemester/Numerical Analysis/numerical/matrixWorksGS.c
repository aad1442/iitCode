//Gauss Elimination
//Determinant
//Root finding
//Inverted Mat

#include <stdio.h>
#define N 5
void initializa(int matrix[N][N + 1], double mat[N][2 * N + 1])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col <= N; col++)
        {
            mat[row][col] = matrix[row][col];
        }
        for (int col = N + 1; col < 2 * N + 1; col++)
        {
            if (col - N - 1 == row)
            {
                mat[row][col] = 1.0;
            }
            else
            {
                mat[row][col] = 0.0;
            }
        }
    }
}
void print(double mat[N][2 * N + 1])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col <= 2 * N; col++)
        {
            printf("%.2lf     ", mat[row][col]);
        }
        printf("\n");
    }
}

void lowerTriElimination(double A[N][2 * N + 1])
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
            for (j = 0; j < 2 * N + 1; j++)
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

            for (k = i; k < 2 * N + 1; k++)
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

double det(double mat[N][2 * N + 1])
{
    double determinent = 1;
    for (int i = 0; i < N; i++)
    {
        determinent *= mat[i][i];
    }
    return determinent;
}
void upperTriangularElimination(double A[N][2 * N + 1])
{
    for (int i = N - 1; i > 0; i--)
    {
        // Ensure that the diagonal element is nonzero
        if (A[i][i] == 0)
        {
            printf("No unique solution exists\n");
            return;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            double m = A[j][i] / A[i][i];

            for (int k = i; k < 2 * N + 1; k++)
            {
                A[j][k] -= m * A[i][k];
            }
        }
    }

    // If the diagonal element of the top row is zero, no unique solution exists
    if (A[0][0] == 0)
    {
        printf("No unique solution exists\n");
        return;
    }
}

void findInverse(double mat[N][2 * N + 1])
{
    double A[N][2 * N + 1];
    double inverse[N][N];
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < 2 * N + 1; col++)
        {
            A[row][col] = mat[row][col];
        }
    }

    for (int row = 0; row < N; row++)
    {
        double diag = A[row][row];
        for (int col = 0; col < 2 * N + 1; col++)
        {
            A[row][col] /= diag;
        }
    }
    printf("inverse matrix:\n");
    for (int row = 0; row < N; row++)
    {
        for (int col = N+1; col < 2 * N+1; col++)
        {
            printf("%.2lf\t\t", A[row][col]);
        }
        printf("\n");
    }
}
int main()
{
    int matrix[3][4] = {
        {1, 0, -1, 0,160},
        {1, -1, 0, 0,240},
        {0, 1, 0, -1,-600},
        {0, 0,-1, 1, 520}};
    double X[N];
    double mat[N][2 * N + 1];
    initializa(matrix, mat);
    print(mat);
    printf("lower triangular elimination\n");
    lowerTriElimination(mat);
    printf("\n");
    print(mat);
    printf("\nDeterminent: %.2lf\n", det(mat));
    upperTriangularElimination(mat);
    printf("Upper triangular elimination\n");
    print(mat);

    findInverse(mat);
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("Root x%d: %.2lf\n", i + 1, mat[i][N] / mat[i][i]);
    }
}
