// =============================================================================
//
//    include/terminal.h	
//
//    By: alkuzin < >                                                     	
//
//    Updated: 20/10/2023 18:11:19                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
#ifndef LIBFTERM_H
#define LIBFTERM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

#include "ui/ui.h"
#include "login/login.h"
#include "terminal/terminal.h"

#define TITLE_SIZE 128
#define OPTION_SIZE 128
#define CONTENT_SIZE 512
#define DEFAULT_DELAY 50

#define TEXT 0
#define DIRECTORY 1
#define ERROR 2

typedef struct
{
    char title[32];
    int content_type;
    void* content;
}option_t;

// listen keys
int getch(void);

void hide_cursor(void);

void show_cursor(void);

void set_title(const char* title);

void set_parent_window(option_t* options_list);

// set option content (text, list of options or error)
void set_option_content(option_t* option, void* content);

// set option content type (text, list of options or error)
void set_option_content_type(option_t* option, int content_type);

void print_options(const option_t* options_list, const int size);

// interactive options selection
void select_option(option_t* options_list, const int size);

// print option's content
void print_content(option_t* options_list, int size);

// print text with time delay
void slow_print(const char* text, int delay);

#endif /* LIBFTERM_H */
