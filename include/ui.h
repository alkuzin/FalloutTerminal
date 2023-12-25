// =============================================================================
//
//    include/ui.h	
//
//    By: alkuzin < >                                                     	
//
//    Updated: 20/10/2023 19:55:57                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
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
  
#define COLOR_BLINK     "\033[5m"
#define COLOR_REVERSE   "\033[7m"
#define COLOR_RESET     "\033[0m"

extern char primary_color[COLOR_SIZE];
extern char error_color[COLOR_SIZE];

void set_primary_color(const char* color);

// set error messages color
void set_error_color(const char* color);

// print custom colored text
void puts_custom_col(const char* string, const char* color, const char* style);

// print prime colored text
void puts_col(const char* string);

// print reverse colored text
void puts_rev_col(const char* string);

// print colored error text
void puts_err_col(const char* string);

// print colored blinking text
void puts_blink_col(const char* string);

#endif
