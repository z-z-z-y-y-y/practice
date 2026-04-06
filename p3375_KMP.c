#include <stdio.h>
#include <string.h>

void get_pi(char *s, int *pi)
{
    int len = strlen(s);
    int j = 0;
    pi[0] = 0;
    for (int i = 1; i < len; i++)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[j] == s[i])
        {
            j++;
        }
        pi[i] = j;
    }
}

void strcompare(char *s1, char *s2, int *pi)
{
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    int j = 0;
    for (int i = 0; i < len_s1; i++)
    {
        while (j > 0 && s1[i] != s2[j])
        {
            j = pi[j - 1];
        }
        if (s1[i] == s2[j])
        {
            j++;
        }
        if (j == len_s2)
        {
            printf("%d\n", i - len_s2 + 2);
        }
    }
}

int main()
{
    char s1[1000005];
    char s2[1000005];
    scanf(" %s", s1);
    scanf(" %s", s2);

    int pi_2[1000005];
    get_pi(s2, pi_2);

    strcompare(s1, s2, pi_2);

    int len = strlen(s2);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", pi_2[i]);
    }
    return 0;
}