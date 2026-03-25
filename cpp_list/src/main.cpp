#include <stdio.h>
#include "list.hpp"

int main(int argc, char** argv)
{
    List list;

    int number=0;
    int num_read=0;
    printf("Eine Nummer nach der anderen eingeben (alles andere bricht ab!) :\n");
    do
    {
        num_read = scanf("%i", &number);

        if(num_read!=0) list.push_back(number);
        
    }while(num_read==1);

    list.print_reverse();
    printf("\n\n");
    list.print();
    printf("\n\n");
    
    return 0;
}
