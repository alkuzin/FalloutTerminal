// =============================================================================
//
//    src/ui.c	
//
//    By: alkuzin < >                                                     	
//
//    Updated: 18/10/2023 21:41:22                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
#include "../include/ui.h"

char primary_color[COLOR_SIZE];
char error_color[COLOR_SIZE];

void set_primary_color(const char* color)
{
    strncpy(primary_color, color, COLOR_SIZE);
}

void set_error_color(const char* color)
{
    strncpy(error_color, color, COLOR_SIZE);
}

static void puts_custom_col(const char* string, const char* color, const char* style)
{
    printf("%s%s%s%s\n", color, style, string, COLOR_RESET);
}

void puts_col(const char* string)
{
    puts_custom_col(string, primary_color, "");
}

void puts_rev_col(const char* string)
{
    puts_custom_col(string, primary_color, COLOR_REVERSE);
}

void puts_err_col(const char* string)
{
    puts_custom_col(string, primary_color, error_color);
}

void puts_blink_col(const char* string)
{
    puts_custom_col(string, primary_color, COLOR_BLINK);   
}