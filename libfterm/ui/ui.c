/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ui.c                                                                     */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/25 21:22:31 by alkuzin                                  */
/*   Updated: 2023/12/26 09:36:24 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int primary_color;
int error_color;

void set_primary_color(int color)
{
    primary_color = color;
}

void set_error_color(int color)
{
    error_color = color;
}

void print_custom_col(const char *string, int color, int style)
{
    printf("\033[%dm\033[%dm%s\033[0m\n", color, style, string);
}

void print_col(const char *string)
{
    print_custom_col(string, primary_color, STYLE_RESET);
}

void print_rev_col(const char *string)
{
    print_custom_col(string, primary_color, STYLE_REVERSE);
}

void print_err_col(const char *string)
{
    print_custom_col(string, primary_color, error_color);
}

void print_blink_col(const char *string)
{
    print_custom_col(string, primary_color, STYLE_BLINK);   
}
