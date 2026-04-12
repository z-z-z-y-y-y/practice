#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007LL

long long exgcd(long long a, long long b, long long *x, long long *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    *y -= a / b * (*x);
    return d;
}

long long inv(long long a)
{
    long long x, y;
    exgcd(a, MOD, &x, &y);
    return (x % MOD + MOD) % MOD;
}

int main()
{
    int N;
    scanf("%d", &N);

    long long **input = (long long **)malloc(sizeof(long long *) * N);
    for (int i = 0; i < N; i++)
    {
        input[i] = (long long *)malloc(sizeof(long long) * 2 * N);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%lld", &input[i][j]);
        }
        for (int j = N; j < 2 * N; j++)
        {
            input[i][j] = 0;
        }
        input[i][i + N] = 1;
    }

    for (int i = 0; i < N; ++i)
    {
        int pivot = -1;
        for (int j = i; j < N; ++j)
        {
            if (input[j][i] != 0)
            {
                pivot = j;
                break;
            }
        }

        if (pivot == -1)
        {
            printf("No Solution\n");
            return 0;
        }

        if (pivot != i)
        {
            long long *temp_i = input[pivot];
            input[pivot] = input[i];
            input[i] = temp_i;
        }

        long long inv_pivot = inv(input[i][i]);
        for (int j = i; j < 2 * N; ++j)
        {
            input[i][j] = input[i][j] * inv_pivot % MOD;
        }

        for (int j = 0; j < N; ++j)
        {
            if (j == i)
            {
                continue;
            }
            long long factor = input[j][i];
            if (factor == 0)
            {
                continue;
            }
            for (int k = i; k < 2 * N; ++k)
            {
                input[j][k] = (input[j][k] - factor * input[i][k]) % MOD;
                if (input[j][k] < 0)
                {
                    input[j][k] += MOD;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = N; j < 2 * N; ++j)
        {
            printf("%lld%c", input[i][j], " \n"[j == 2 * N - 1]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        free(input[i]);
    }
    free(input);

    return 0;
}