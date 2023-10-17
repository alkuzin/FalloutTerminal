#include "../include/terminal.h"

int main(void)
{
    const int size = 3;
    option_t option_list[size];

    option_list[0] = (option_t){.title="View Access Logs", .content=access_logs_text, .content_type="text"};
    option_list[1] = (option_t){.title="Incident Reports", .content="---> Incident Reports text <---", .content_type="text"};
    option_list[2] = (option_t){.title="Personal Notes", .content=NULL, .content_type="directory"};

    set_main_title("==== Institute Central Network ====\n"
                   "Advanced Systems Terminal 1A\n\n");
                   
    printf("%s... Print any button to start ...%s\n\n", main_color, RESET);
    slow_print(main_title, DEFAULT_DELAY);
    select_option(option_list, size);
    
    return 0;
}