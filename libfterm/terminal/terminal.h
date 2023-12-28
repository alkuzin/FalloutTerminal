/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   terminal.h                                                               */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/25 22:02:58 by alkuzin                                  */
/*   Updated: 2023/12/28 12:45:16 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
#define TERMINAL_H

#include "../libfterm.h"

#define DEFAULT_FIELD_WIDTH 64
#define DEFAULT_PARENT_WINDOW NULL

typedef struct {
    char title[32];
    int content_type;
    void *content;
} option_t;

// initialize terminal
extern void init_terminal(option_t *options_list, int size);

// hide mouse cursor
extern void hide_cursor(void);

// show mouse cursor
extern void show_cursor(void);

// set terminal title
extern void set_title(const char *new_title);

// set hightlighted area field width
extern void set_field_width(int width);

// set option content (text, list of options or error)
extern void set_option_content(option_t *option, void* content);

// set option content type (text, list of options or error)
extern void set_option_content_type(option_t *option, int content_type);

// interactive options selection
extern void select_option(option_t *options_list, const int size);

// print text with time delay
extern void slow_print(const char *text, int delay);

#endif /* TERMINAL_H */
