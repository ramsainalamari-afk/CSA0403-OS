#include <stdio.h>

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void rsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void bestfit(int mp[], int p[], int m, int n)
{
    int used[20] = {0};

    for (int i = 0; i < m; i++)
    {
        int best = -1;

        for (int j = 0; j < n; j++)
        {
            if (!used[j] && mp[j] >= p[i])
            {
                if (best == -1 || mp[j] < mp[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            printf("\n%d fits in %d", p[i], mp[best]);
            mp[best] = mp[best] - p[i];
            used[best] = 1;
        }
        else
        {
            printf("\n%d must wait for its process", p[i]);
        }
    }
}

void firstfit(int mp[], int p[], int m, int n)
{
    int used[20] = {0};

    for (int i = 0; i < m; i++)
    {
        int found = -1;

        for (int j = 0; j < n; j++)
        {
            if (!used[j] && mp[j] >= p[i])
            {
                found = j;
                break;
            }
        }

        if (found != -1)
        {
            printf("\n%d fits in %d", p[i], mp[found]);
            mp[found] -= p[i];
            used[found] = 1;
        }
        else
        {
            printf("\n%d must wait for its process", p[i]);
        }
    }
}

void worstfit(int mp[], int p[], int m, int n)
{
    int used[20] = {0};

    for (int i = 0; i < m; i++)
    {
        int worst = -1;

        for (int j = 0; j < n; j++)
        {
            if (!used[j] && mp[j] >= p[i])
            {
                if (worst == -1 || mp[j] > mp[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            printf("\n%d fits in %d", p[i], mp[worst]);
            mp[worst] -= p[i];
            used[worst] = 1;
        }
        else
        {
            printf("\n%d must wait for its process", p[i]);
        }
    }
}

int main()
{
    int m, n, mp[20], p[20], ch;

    printf("Number of memory partition : ");
    scanf("%d", &n);

    printf("Number of process : ");
    scanf("%d", &m);

    printf("Enter the memory partitions :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mp[i]);
    }

    printf("Enter process size :\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("\n1. First Fit\t2. Best Fit\t3. Worst Fit");
    printf("\nEnter your choice : ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            firstfit(mp, p, m, n);
            break;

        case 2:
            bestfit(mp, p, m, n);
            break;

        case 3:
            worstfit(mp, p, m, n);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}