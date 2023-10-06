#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdio.h>

extern char main_title[128];

typedef struct
{
    char title[32];
    void* content;
}option_t;


void print_options(option_t* options_list, int size);

void set_main_title(char* title);

#endif