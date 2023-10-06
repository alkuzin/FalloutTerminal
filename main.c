#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

int main(void)
{
    const int size = 3;
    option_t option_list[size];

    option_list[0] = (option_t){.title="option 1", .content="-"};
    option_list[1] = (option_t){.title="option 2"};
    option_list[2] = (option_t){.title="option 3"};

    print_options(option_list, size);
    
    

    return 0;
}