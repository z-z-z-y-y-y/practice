#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    double **determinant = (double **)malloc(sizeof(double *) * n);
    for (int i = 0; i < n; i++)
    {
        determinant[i] = (double *)malloc(sizeof(double) * (n + 1));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%lf", &determinant[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(determinant[j][i]) > fabs(determinant[max][i]))
            {
                max = j;
            }
        }
        if (max != i)
        {
            double *temp = determinant[max];
            determinant[max] = determinant[i];
            determinant[i] = temp;
        }
        if (determinant[i][i] == 0.0)
        {
            printf("No Solution\n");
            return 0;
        }
        for (int j = n; j >= i; j--)
        {
            determinant[i][j] /= determinant[i][i];
        }
        for (int j = i + 1; j < n; j++)
        {
            for (int k = n; k >= i; k--)
            {
                determinant[j][k] -= determinant[i][k] * determinant[j][i];
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            determinant[j][n] -= determinant[i][n] * determinant[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf\n", determinant[i][n]);
    }
    return 0;
}