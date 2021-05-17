#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *ptr;
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        printf("aa : %s\n", argv[i]);
        i++;
    }
    return (0);
}