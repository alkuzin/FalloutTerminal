#include "terminal.h"

char main_title[128];
char access_logs_text[512] = 
"Access: Local. Login: Li.M\n"
"Notes: Review of Phase Three project status\n\n"
"Access: Local. Login: Li.M\n"
"Notes: update diagnostic tools for child synth project\n\n"
"Access: Remote. Login: DIRECTOR\n"
"Notes: --REDACTED--\n\n"
"Access: Local. Login: Li.M\n"
"Notes: Review of all BioScience projects\n\n\n";

void print_options(const option_t* options_list, int size, const int selected) 
{
    char buffer[64];
    for (int i = 0; i < size; i++)
    {
        if (i == selected)
            snprintf(buffer, sizeof(buffer), "[%s]\t<---\n", options_list[i].title);
        else
            snprintf(buffer, sizeof(buffer), "[%s]\n", options_list[i].title);
        puts(buffer);
    }
}

void set_main_title(const char* title)
{
    strncpy(main_title, title, 128);
}

void set_option_content(option_t* option, void* content)
{
    if (strncmp(option->content_type, "text", 4) == 0)
    {
        option->content = (char*) content;
    }
    else if (strncmp(option->content_type, "directory", 10) == 0)
    {
        option->content = (option_t*) content;
    }
}

void slow_print(const char* text, int delay)
{
    int i = -1;
    while (text[++i] != '\0')
    {
        putchar(text[i]);
        fflush(stdout);
        usleep(delay * 500);
    }
}

int getch(void) 
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

void select_option(const option_t* options_list, const int size)
{
    int ch;
    int selected;
    selected = 0;

    puts("START");

    while (ch = getch())
    {
        if (ch == '\033')
        {
            getch();
            switch (getch())
            {
            case 'A':
                selected--;
                puts("^");
                break;
            
            case 'B':
                puts("|");
                selected++;
                break;
            
            default:
                break;
            }
        }

        if (selected < 0)
            selected = size - 1;
        else if (selected >= size)
            selected = 0;

        puts("END");

        print_options(options_list, size, selected);
        system("clear");
    }
}