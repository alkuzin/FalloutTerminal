#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <string.h>

#define COLOR_SIZE 6

#define COLOR_WHITE     "\033[97m"
#define COLOR_BLACK     "\033[30m"
#define COLOR_RED       "\033[31m"
#define COLOR_GREEN     "\033[92m"
#define COLOR_CYAN      "\033[96m"
  
#define COLOR_REVERSE   "\033[7m"
#define COLOR_RESET     "\033[0m"

extern char primary_color[COLOR_SIZE];
extern char error_color[COLOR_SIZE];

void set_primary_color(const char* color);

// set error messages color
void set_error_color(const char* color);

// print colored text
void puts_col(const char* string);

// print reverse colored text
void puts_rev_col(const char* string);

// print colored error text
void puts_err_col(const char* string);

#endif