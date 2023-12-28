/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libfterm.h                                                               */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/26 09:07:15 by alkuzin                                  */
/*   Updated: 2023/12/26 10:29:13 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTERM_H
#define LIBFTERM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

#include "ui/ui.h"
#include "login/login.h"
#include "terminal/terminal.h"

#define TITLE_SIZE 128
#define OPTION_SIZE 128
#define CONTENT_SIZE 512
#define DEFAULT_DELAY 50

extern int field_width;

enum { 
    TEXT=0,
    DIRECTORY=1,
    ERROR=2
};

#endif /* LIBFTERM_H */
