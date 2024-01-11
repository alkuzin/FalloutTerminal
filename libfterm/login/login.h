/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   login.h                                                                  */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/25 21:53:14 by alkuzin                                  */
/*   Updated: 2024/01/11 11:35:03 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIN_H
#define LOGIN_H
 
#include "../libfterm.h"

#define MAX_ATTEMPTS   5
#define INPUT_SIZE     10
#define PASSW_MAX_LEN  16
#define STRING_ROWS    12
#define STRING_SIZE    16

/* initialize user authorisation */
extern int login(void);

/* successful user authorisation window*/ 
extern void login_success(const char *success_msg);

/* failed user authorisation window */
extern void login_failure(const char *failure_msg);

/* set authorisation window title */
extern void set_login_title(char* new_title);

/* get authorisation window title  */ 
extern char *get_login_title(void);

extern void get_password(void);

#endif /* LOGIN_H */ 
