#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b) 

void tracking(char s[], char t[], int n, int m, int dp[][m + 1])
{
    char lcs[100];
    int idx = 0;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            lcs[idx++] = s[i - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for (int i = idx - 1; i >= 0; i--)
        printf("%c", lcs[i]);
}

int main()
{
    char s[100], t[100];

    fgets(s, 100, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';

    fgets(t, 100, stdin);
    if (t[strlen(t) - 1] == '\n') t[strlen(t) - 1] = '\0';

    int lens = strlen(s);
    int lent = strlen(t);

    int dp[lens + 1][lent + 1];
    for (int i = 0; i <= lens; i++)
        for (int j = 0; j <= lent; j++)
            dp[i][j] = 0;
    
    for (int i = 1; i <= lens; i++)
    {
        for (int j = 1; j <= lent; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("Do dai LCS: %d\n", dp[lens][lent]);
    printf("LCS: ");
    tracking(s, t, lens, lent, dp);

    return 0;
}