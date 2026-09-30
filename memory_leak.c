#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr;

    ptr = malloc(10 * sizeof(int));

    if (ptr == NULL)
    {
        printf("malloc() failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        ptr[i] = i + 1;
    }

    printf("Memory allocated successfully.\n");

    /* Intentionally not calling free(ptr) */

    return 0;
}
