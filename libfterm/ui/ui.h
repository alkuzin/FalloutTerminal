/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ui.h                                                                     */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/26 08:50:59 by alkuzin                                  */
/*   Updated: 2023/12/26 08:51:01 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
#define UI_H

#include "../libfterm.h"

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

extern int primary_color;
extern int error_color;

extern void set_primary_color(int color);

// set error messages color
extern void set_error_color(int color);

// print custom colored text
extern void print_custom_col(const char *string, int color, int style);

// print prime colored text
extern void print_col(const char *string);

// print reverse colored text
extern void print_rev_col(const char *string);

// print colored error text
extern void print_err_col(const char *string);

// print colored blinking text
extern void print_blink_col(const char *string);

#endif /* UI_H */
