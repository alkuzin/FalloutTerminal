/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/26 09:42:25 by alkuzin                                  */
/*   Updated: 2023/12/26 10:25:09 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#include "libfterm/libfterm.h"

int main(void)
{
    // set default settings
    const char* main_title = 
    "==== Institute Central Network ====\n"
    "Advanced Systems Terminal 1A     \n\n";

    set_primary_color(COLOR_WHITE);
    set_error_color(COLOR_RED);
    set_title(main_title);
    set_field_width(64);

    // initialize login process
    if (login())
    {
        hide_cursor();
        system("clear");

        print_col(get_login_title());
        slow_print("\nLOGIN AS ADMINISTRATOR\n"
        "PASSWORD: * * * * *\n\nSTATUS: COMPLETE\n\n\n", DEFAULT_DELAY);
        print_blink_col("[press <enter> to continue]");

        getchar();
    }
    else
    {
        system("clear");
        lock_out_terminal();
        puts("\033]0m");
    }
    system("clear");

    // set options
    int size = 3;
    option_t option_list[size];
    option_t opt_list_personal_notes[2];

    opt_list_personal_notes[0] = (option_t)
    {
        .title="Cold Fusion",
        .content=
        "Proposal:\n\n"
        "Divert time/materials from current Phase Three research to exploring the\n"
        "possibility of sustainable nuclear reactions through electrochemical processes at\n"
        "or near room temperatures. Pre-war work on the subject yielded no concrete\n"
        "results; advances in technology could potentially make it possible.\n\n"
        "Approval:\n\n"
        "Rejected - Li.M\n"
        "Notes: Evidence suggests this is, and always will be, a pipe dream.\n",
        .content_type=TEXT
    };

    opt_list_personal_notes[1] = (option_t)
    {
        .title="Surface Work Crew Tracking",
        .content=
        "Group Ident: G1486\n"
        "Assigned Units: R7-81, T3-54, B8-88, J1-74\n"
        "Location: Site Alpha\n"
        "Elapsed Time: 160:33:12\n"
        "Last Report: 1:56:40\n\n"
        "NOTES:\n"
        "Unit B8-88 removed, unit T3-54 added. [ERROR, NO DATA PRESENT]\n",
        .content_type=TEXT
    };

    option_list[0] = (option_t)
    {
        .title="View Access Logs",
        .content= 
        "Access: Local. Login: Li.M\n"
        "Notes: Review of Phase Three project status\n\n"
        "Access: Local. Login: Li.M\n"
        "Notes: update diagnostic tools for child synth project\n\n"
        "Access: Remote. Login: DIRECTOR\n"
        "Notes: --REDACTED--\n\n"
        "Access: Local. Login: Li.M\n"
        "Notes: Review of all BioScience projects\n\n\n",
        .content_type=TEXT
    };

    option_list[1] = (option_t)
    {
        .title="Incident Reports",
        .content=
        "   ****Incident Reports****\n\n\n"
        "Incident IN2845t\n\n"
        "Patient: Thompson.E\n"
        "Presenting symptom: First-degree burns, left hand\n"
        "Notes: Patient placed his hand inside power\n"
        "relay without first disengaging. First aid applied.\n",     
        .content_type=TEXT
    };

    option_list[2] = (option_t)
    {
        .title="Personal Notes", 
        .content=&opt_list_personal_notes,
        .content_type=DIRECTORY
    };

    // initializing terminal
    slow_print(main_title, DEFAULT_DELAY);
    set_parent_window(option_list);
    select_option(option_list, size);
    return 0;
}
