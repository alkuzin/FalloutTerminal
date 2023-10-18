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

void puts_col(const char* string)
{
    printf("%s%s%s\n", primary_color, string, COLOR_RESET);
}

void puts_rev_col(const char* string)
{
    printf("%s%s%s%s\n", COLOR_REVERSE, primary_color, string, COLOR_RESET);
}

void puts_err_col(const char* string)
{
    printf("%s%s%s\n", error_color, string, COLOR_RESET);
}