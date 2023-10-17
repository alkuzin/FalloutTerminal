#include "terminal.h"

int main(void)
{
    // char ch;
    const int size = 3;
    option_t option_list[size];

    option_list[0] = (option_t){.title="View Access Logs", .content=access_logs_text, .content_type="text"};
    option_list[1] = (option_t){.title="Incident Reports", .content="-", .content_type="text"};
    option_list[2] = (option_t){.title="Personal Notes", .content="-", .content_type="directory"};

    // set_main_title("==== Institute Central Network ====\n"
    //                "Advanced Systems Terminal 1A\n\n");

    // // ch = getch();

    // slow_print(main_title, DEFAULT_DELAY);
    // print_options(option_list, size, -1);

    puts("BEGIN");
    getch();
    select_option(option_list, size);

    getchar();
    getchar();
    system("clear");
    slow_print(main_title, DEFAULT_DELAY);
    slow_print(option_list[0].content, DEFAULT_DELAY);

    return 0;
}