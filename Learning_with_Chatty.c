#include <stdio.h>

int main(void)
{
    int arr[5];

    printf("arr      = %p\n", (void*)arr);
    printf("&arr[0]  = %p\n", (void*)&arr[0]);

    printf("Vergleich: %d\n", arr == &arr[0]);

    if (arr == &arr[0])
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }

    return 0;
}