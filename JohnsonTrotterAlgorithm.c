#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int perm[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);

    printf("\n");
}

int getMobile(int perm[], int dir[], int n)
{
    int mobile = 0;
    int mobile_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (dir[perm[i] - 1] == LEFT && i != 0)
        {
            if (perm[i] > perm[i - 1] && perm[i] > mobile)
            {
                mobile = perm[i];
                mobile_index = i;
            }
        }

        if (dir[perm[i] - 1] == RIGHT && i != n - 1)
        {
            if (perm[i] > perm[i + 1] && perm[i] > mobile)
            {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }

    return mobile;
}

int search(int perm[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
    {
        if (perm[i] == mobile)
            return i;
    }

    return -1;
}

void generatePermutations(int n)
{
    int perm[n], dir[n];

    for (int i = 0; i < n; i++)
    {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1)
    {
        int mobile = getMobile(perm, dir, n);

        if (mobile == 0)
            break;

        int pos = search(perm, n, mobile);

        if (dir[mobile - 1] == LEFT)
        {
            int temp = perm[pos];
            perm[pos] = perm[pos - 1];
            perm[pos - 1] = temp;
        }
        else
        {
            int temp = perm[pos];
            perm[pos] = perm[pos + 1];
            perm[pos + 1] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            if (perm[i] > mobile)
            {
                dir[perm[i] - 1] *= -1;
            }
        }

        printPermutation(perm, n);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    generatePermutations(n);

    return 0;
}
