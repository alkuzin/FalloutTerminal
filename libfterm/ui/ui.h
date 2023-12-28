/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ui.h                                                                     */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/26 08:50:59 by alkuzin                                  */
/*   Updated: 2023/12/28 12:51:06 by alkuzin                                  */
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

// set terminal primary color
extern void set_primary_color(int color);

// set error messages color
extern void set_error_color(int color);

// print prime colored text
extern void print_col(const char *string);

// print reverse colored text
extern void print_rev_col(const char *string);

// print colored error text
extern void print_err_col(const char *string);

// print colored blinking text
extern void print_blink_col(const char *string);

// change color (should be reset later by reset_color())
extern void change_col(int color);

// reset color selected by change_col()
extern void reset_color(void);

#endif /* UI_H */
