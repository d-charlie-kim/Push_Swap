#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int     *intag;
    int     count;
    int     i;
    int     j;
    int     temp;

    i = 0;
    j = 0;
    if (argc != 2)
    {
        printf("Error");
        return (0);
    }
    intag = (int *)malloc(sizeof(int) * 5);
    while (i < 5)
    {
        intag[i] = 0;
        i++;
    }
    i = 0;
    while (argv[1][i])
    {
        while (argv[1][i] != ' ' && argv[1][i])
        {
            intag[j] = (intag[j] * 10) + argv[1][i] - '0';
            i++;
        }
        j++;
        i++;
    }
    j = 0;
    while (j < 5)
    {
        printf("ag : %d\n", intag[j]);
        j++;
    }
    return (0);
}