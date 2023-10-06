#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

extern char main_title[128];
extern char access_logs_text[512];
#define DEFAULT_DELAY 50

typedef struct
{
    char title[32];
    char content_type[16];
    void* content;
}option_t;


void print_options(option_t* options_list, int size);

void set_main_title(char* title);

void set_option_content(option_t* option, void* content);

void slow_print(char* text, int delay);

int getch(void);

#endif