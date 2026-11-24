#include <stdio.h>
#define INF 999999
int n;
int cost[10][10];
int dp[10][1024];
int tsp(int curr, int visited)
{
    if (visited == (1 << n) - 1)
        return cost[curr][0];

    if (dp[curr][visited] != -1)
        return dp[curr][visited];

    int ans = INF;

    for (int i = 0; i < n; i++)
    {
        if (!(visited & (1 << i)))
        {
            int total = cost[curr][i] +
                        tsp(i, visited | (1 << i));

            if (total < ans)
                ans = total;
        }
    }
    return dp[curr][visited] = ans;
}

int main()
{
    int i, j;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    if (n < 2 || n > 10)
    {
        printf("Enter cities between 2 and 10");
        return 0;
    }
    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (1 << n); j++)
        {
            dp[i][j] = -1;
        }
    }

    printf("Minimum travelling cost = %d\n",
           tsp(0, 1));
    return 0;
}
