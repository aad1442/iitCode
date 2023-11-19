#include <stdio.h>
#include <math.h>
#define max 5
int row, col;
double x[max], fx[max];
double mat[max][max], matTrans[max][max], matInv[max][max];

double operationalMat[max][2 * max];

void multiplication(double matA[max][max], double matB[max][max],
                    double result[max][max], int row1, int row2, int col2)
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
    /* printf("multiplication result: \n");
     for (int i = 0; i < row1; i++) {
         printf("|");
         for (int j = 0; j < col2; j++) {
             printf(" %lf\t", result[i][j]);
         }
         printf("| ");
         printf("\n");
     }*/
}

void multiplication3x1(double matA[3][max], double matB[][1], double result[3][1], int row1, int col1, int col2)
{
    for (int i = 0; i < row1; i++)
    {
        result[i][0] = 0;
        for (int k = 0; k < col1; k++)
        {
            result[i][0] += matA[i][k] * matB[k][0];
        }
    }
    /*printf("Multiplication result: \n");
    for (int i = 0; i < row1; i++) {
        printf("| %lf |\n", result[i][0]);
    }*/
}
void gaussianElimination(double A[max][2 * max], int N)
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

void augmented(double A[][max], int N)
{
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

    gaussianElimination(operationalMat, N);
}
void readInput()
{
    freopen("lssConstant.txt", "r", stdin);
    // printf("enter row, col: ");
    scanf("%d %d", &row, &col);

    for (int i = 0; i < col; i++)
    {
        // printf("enter x[i]: ");
        scanf("%lf", &x[i]);
    }
    for (int i = 0; i < col; i++)
    {
        // printf("enter fx[i]: ");
        scanf("%lf", &fx[i]);
    }

    for (int j = 0; j < col; j++)
    {
        mat[0][j] = 1.0;
        mat[1][j] = x[j];
        mat[2][j] = x[j] * x[j];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matTrans[j][i] = mat[i][j];
        }
    }
}

int main()
{
    double mulRight[3][1], mulLeft[max][max], solve[3][1];
    double fy[][1] = {
        {1}, {0}, {1}, {2}};

    readInput();
    multiplication(mat, matTrans, mulLeft, 3, 4, 3);
    multiplication3x1(mat, fy, mulRight, 3, 4, 1);
    augmented(mulLeft, 3);

    int column;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 3, column = 0; j < 2 * 3, column < 3; j++, column++)
        {

            matInv[i][column] = operationalMat[i][j];
        }
    }

    multiplication3x1(matInv, mulRight, solve, 3, 4, 1);
    for (int i = 0; i < 3; i++)
    {
        printf("c%d = %0.2lf\n", i + 1, solve[i][0]);
    }

    return 0;
}
