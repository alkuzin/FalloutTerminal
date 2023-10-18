// =============================================================================
//
//    include/terminal.h	
//
//    By: alkuzin <---@gmail.com>                                         	
//
//    Updated: 17/10/2023 22:38:02                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "ui.h"

extern char main_title[128];
extern char access_logs_text[512];

#define DEFAULT_DELAY 50

typedef struct
{
    char title[32];
    char content_type[16];
    void* content;
}option_t;

void print_options(const option_t* options_list, const int size, const int selected);

void set_main_title(const char* title);

void set_option_content(option_t* option, void* content);

void print_content(const option_t* option_list, const int size, const int selected);

void slow_print(const char* text, int delay);

int getch(void);

void select_option(const option_t* options_list, const int size);

void print_main_title(void);

#endif