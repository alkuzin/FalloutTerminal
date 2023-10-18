// =============================================================================
//
//    src/main.c	
//
//    By: alkuzin <---@gmail.com>                                         	
//
//    Updated: 17/10/2023 23:06:24                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
#include "../include/terminal.h"

static char access_logs_text[CONTENT_SIZE] = 
"Access: Local. Login: Li.M\n"
"Notes: Review of Phase Three project status\n\n"
"Access: Local. Login: Li.M\n"
"Notes: update diagnostic tools for child synth project\n\n"
"Access: Remote. Login: DIRECTOR\n"
"Notes: --REDACTED--\n\n"
"Access: Local. Login: Li.M\n"
"Notes: Review of all BioScience projects\n\n\n";

static char data_corrupted[512] = 
"--ERROR DATA CORRUPTED--\n\n"
"r9cjditxchfxirksfjiOJ)(*&^IOFBUi_)**()&...\n\n"
"0000200f  7325 735b 2573 5d25 3634 7309 001b 5b30\n"
"0000201f  6d00 2573 5b25 735d 2573 0025 7325 7325\n" 
"0000202f  730a 0074 6578 7400 6469 7265 6374 6f72\n"
"0000203f  7900 2573 0063 6c65 6172 0025 7325 7325\n";

int main(void)
{
    // set default settings
    const char* main_title = 
    "==== Institute Central Network ====\n"
    "Advanced Systems Terminal 1A     \n\n";

    set_primary_color(COLOR_CYAN);
    set_error_color(COLOR_RED);
    set_title(main_title);

    // set options
    int size = 3;
    option_t option_list[size];

    option_list[0] = (option_t){.title="View Access Logs", .content=access_logs_text, .content_type=TEXT};
    option_list[1] = (option_t){.title="Incident Reports", .content="---> Incident Reports text <---", .content_type=TEXT};
    option_list[2] = (option_t){.title="Personal Notes", .content=data_corrupted, .content_type=ERROR};
    
    // initializing terminal
    hide_cursor();
    puts_col("... Print any button to start ...");
    slow_print(title, DEFAULT_DELAY);
    select_option(option_list, size);

    return 0;
}