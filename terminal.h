#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdio.h>

typedef struct
{
    char title[32];
    void* content;
}option_t;


void print_options(option_t* options_list, int size);

#endif