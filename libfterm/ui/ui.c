/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ui.c                                                                     */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/25 21:22:31 by alkuzin                                  */
/*   Updated: 2023/12/28 15:46:22 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int primary_color;
int error_color;

/* print custom colored text */
static void print_custom_col(const char *string, int color, int style);

void set_primary_color(int color)
{
    primary_color = color;
}

void set_error_color(int color)
{
    error_color = color;
}

void print_col(const char *string)
{
    change_col(primary_color);
    puts(string);
    reset_color();
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

void change_col(int color)
{
	printf("\033[%dm", color);
}

void reset_color(void)
{
	change_col(STYLE_RESET);
}

static void print_custom_col(const char *string, int color, int style)
{
    change_col(color);
    printf("\e[%dm%s\n", style, string);
    reset_color();
}
