#include "terminal.h"

void print_options(option_t* options_list, int size) 
{
    for (int i = 0; i < size; i++)
        printf("[%-s]", options_list[i].title);
}