/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   terminal.h                                                               */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/25 22:02:58 by alkuzin                                  */
/*   Updated: 2023/12/26 10:23:05 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
#define TERMINAL_H

#include "../libfterm.h"

typedef struct {
    char title[32];
    int content_type;
    void *content;
} option_t;

// listen keys
extern int getch(void);

extern void hide_cursor(void);

extern void show_cursor(void);

extern void set_title(const char *new_title);

extern void set_parent_window(option_t *options_list);

extern void set_field_width(int width);

// set option content (text, list of options or error)
extern void set_option_content(option_t *option, void* content);

// set option content type (text, list of options or error)
extern void set_option_content_type(option_t *option, int content_type);

extern void print_options(const option_t *options_list, const int size);

// interactive options selection
extern void select_option(option_t *options_list, const int size);

// print option's content
extern void print_content(option_t *options_list, int size);

// print text with time delay
extern void slow_print(const char *text, int delay);

#endif /* TERMINAL_H */
