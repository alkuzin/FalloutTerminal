# libfterm 1.0 Documentation

## Contents

1. [Introduction](#1-introduction)
2. [Installation](#2-installation)
3. [Common components](#3-common-components)
4. [Login functions](#4-login-functions)
5. [Terminal functions](#5-terminal-functions)
6. [UI functions](#6-ui-functions)
7. [Usage template](#7-usage-template)

## 1. Introduction

Libfterm - simple library for creating terminal interface inspired from [Fallout 4](https://fallout.bethesda.net/en/games/fallout-4).


## 2. Installation

First clone this repository:
```console
git clone https://github.com/alkuzin/FalloutTerminal.git
```
Then move to __`FalloutTerminal/`__ directory and run:
```console
make all && make clean
```
Then include [__`libfterm.h`__](../libfterm/libfterm.h) header file in your project.
```c
#include "<path to your project>/libfterm/libfterm.h"
/* project code here */
```
Finaly compile your project, including __`libfterm.a`__ file.

## 3. Common components

The terminal contains several options. 

There is a structure **option_t**, that describes option's properties:
```c
typedef struct {
    char title[32];    // option's title text 
    int content_type;  // option's type of content (text, directory or error)  
    void *content;     // content pointer (it can be char * or option_t *) 
} option_t;
```

Type of content enumeration:
```c
enum { 
    TEXT=0,
    DIRECTORY=1,
    ERROR=2
};
```

Enumeration of colors and text styles (ANSI):
```c
enum {
    COLOR_WHITE    = 97,
    COLOR_BLACK    = 30,
    COLOR_RED      = 31,
    COLOR_GREEN    = 92,
    COLOR_CYAN     = 96,

    STYLE_BLINK    = 5,
    STYLE_REVERSE  = 7,
    STYLE_RESET    = 0
};
```

## 4. Login functions

The login functions are responsible for the process of user's logging in:

```c
// initialize user authorisation
// return 1 when logging in is successful, 0 is logging in failed
extern int login(void);

// get string input from user
extern void getinput(char* buffer);

// lock out terminal in case of 5 failed attempts of logging in
extern void lock_out_terminal(void);

// set login custom title
extern void set_login_title(char* new_title);

// get login title
extern char *get_login_title(void);

// return pseudorandom integer from lower_range to upper_range
extern int randint(int lower_range, int upper_range);
```

> [!WARNING]
>  Default password is using for tests, it is better to use enviroment variables in this case!

## 5. Terminal functions

The terminal functions are responsible for the operation of the terminal after logging in:
```c
// read a character input from the keyboard.
extern int getch(void); 

// hide mouse cursor
extern void hide_cursor(void); 

// show mouse cursor
extern void show_cursor(void); 

// set custom option title
extern void set_title(const char *new_title); 

// set parent window (for options which contains directory)
extern void set_parent_window(option_t *options_list); 

// set width of highlighted area field
extern void set_field_width(int width); 

// set option content (text, directory or error)
extern void set_option_content(option_t *option, void* content);

// set option content type (text, directory or error)
extern void set_option_content_type(option_t *option, int content_type);

// display options list
extern void print_options(const option_t *options_list, const int size);

// interactive options selection
extern void select_option(option_t *options_list, const int size);

// print option's content
extern void print_content(option_t *options_list, int size);

// print text with time delay
extern void slow_print(const char *text, int delay);
```

## 6. UI functions

The UI functions are responsible for the semblance of the user interface:

```c
// set custom primary color
extern void set_primary_color(int color);

// set custom error messages color
extern void set_error_color(int color);

// print custom colored text
extern void print_custom_col(const char *string, int color, int style);

// print prime colored text
extern void print_col(const char *string);

// print reverse colored text
extern void print_rev_col(const char *string);

// print colored error text
extern void print_err_col(const char *string);

// print blinking text
extern void print_blink_col(const char *string);
```
## 7. Usage template

To try this usage template compile [__`main.c`__](../main.c) file, which is attached as an example to the library.

```c
// include header file
#include "libfterm/libfterm.h"

int main(void)
{
    // set default settings
    const char* main_title = "...";

    set_primary_color(COLOR_WHITE);
    set_error_color(COLOR_RED);
    set_title(main_title);
    set_field_width(64);

    // initialize login process
    if (login())
    {
        hide_cursor();
        system("clear");

        print_col(get_login_title());
        // print successful login message
        slow_print("...", DEFAULT_DELAY);

        // wait pressing key from user
        print_blink_col("[press <enter> to continue]");
        getchar();
    }
    else
    {
        system("clear");
        lock_out_terminal();

        // reseting color
        puts("\033]0m");
    }
    system("clear");

    // set options
    int size = 3;
    option_t option_list[size];
    option_t sub_option_list[2];

    
    option_list[0] = (option_t)
    {
        .title="...",
        .content="...",
        .content_type=TEXT
    };

    option_list[1] = (option_t)
    {
        .title="...",
        .content="...",     
        .content_type=TEXT
    };

    option_list[2] = (option_t)
    {
        .title="...", 
        .content=&sub_option_list,
        .content_type=DIRECTORY
    };

    // set suboptions
    sub_option_list[0] = (option_t)
    {
        .title="...",
        .content="...",
        .content_type=TEXT
    };

    sub_option_list[1] = (option_t)
    {
        .title="...",
        .content="...",
        .content_type=TEXT
    };

    // initializing terminal
    slow_print(main_title, DEFAULT_DELAY);

    set_parent_window(option_list);
    select_option(option_list, size);
    
    return 0;
}
```