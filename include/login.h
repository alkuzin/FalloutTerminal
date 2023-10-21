// =============================================================================
//
//    include/login.h	
//
//    By: alkuzin < >                                                     	
//
//    Updated: 21/10/2023 21:50:49                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/terminal.h"

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

extern char login_title[TITLE_SIZE];

// initialize user authorisation
int login(void);

// get string input from user
void getinput(char* buffer);

void lock_out_terminal(void);

void set_login_title(char* new_title);

int randint(int lower_range, int higher_range);

#endif