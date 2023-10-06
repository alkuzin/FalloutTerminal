#include "terminal.h"

char main_title[128];

void print_options(option_t* options_list, int size) 
{
    for (int i = 0; i < size; i++)
        printf("[%-s]\n", options_list[i].title);
}

void set_main_title(char* title);