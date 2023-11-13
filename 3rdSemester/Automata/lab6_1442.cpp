#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dfa[3][2];
char RE[3][3][3][100];
int main()
{
    freopen("table.txt", "r", stdin);
    printf("Enter the transition table: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &dfa[i][j]);
        }
    }

    printf("Transition table-\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", dfa[i][j]);
        }
        printf("\n");
    }

    printf("Enter the value of R[0][i][j]\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%s", RE[0][i][j]);
        }
    }

    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("RE(0)%d%d %s\n", j, k, RE[j][k]);
        }
    }
    for (int m = 1; m < 3; m++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int k = 1;
                strcpy(RE[m][i][j], RE[m - 1][i][j]);
                strcat(RE[m][i][j], "+");
                strcat(RE[m][i][j], RE[m - 1][i][k]);
                // if(RE[m-1][k][k]!=""){
                strcat(RE[m][i][j], "(");
                strcat(RE[m][i][j], RE[m - 1][k][k]);
                strcat(RE[m][i][j], ")*");
                //}
                strcat(RE[m][i][j], RE[m - 1][k][j]);
            }
        }
    }
    for (int m = 0; m < 3; m++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("RE(%d)%d%d %s\n", m, j, k, RE[m][j][k]);
            }
        }
    }
}
