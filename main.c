#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

int main(void)
{
    const int size = 3;
    option_t* option_list[size];

    option_t option_1 = {.title="option 1"};
    option_t option_2 = {.title="option 2"};
    option_t option_3 = {.title="option 3"};

    print_options(option_list, size);
    
    

    return 0;
}