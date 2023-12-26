/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   login.h                                                                  */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/25 21:53:14 by alkuzin                                  */
/*   Updated: 2023/12/26 09:39:32 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIN_H
#define LOGIN_H

#include "../libfterm.h"

#define MAX_ATTEMPTS 5
#define INPUT_SIZE 10

// This password is using for tests
// Better to use enviroment variables in this case
#define PASSWORD "12345"

#define PASSWORD_SIZE 5
#define PASSWORDS_COUNT 40
#define SELECTED_PASSWORDS_COUNT 8

#define SYMBOLS "!@#$?/^&*()_+=|,.{}[]-"
#define STRING_SIZE 12
#define STRING_ROWS 16

// initialize user authorisation
extern int login(void);

// get string input from user
extern void getinput(char* buffer);

extern void lock_out_terminal(void);

extern void set_login_title(char* new_title);

extern char *get_login_title(void);

extern int randint(int lower_range, int upper_range);

#endif /* LOGIN_H */
