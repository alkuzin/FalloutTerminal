#include "../include/terminal.h"

char* main_color = CYAN;
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

static char data_corrupted[512] = 
"--ERROR DATA CORRUPTED--\n\n"
"r9cjditxchfxirksfjiOJ)(*&^IOFBUi_)**()&...\n\n"
"0000200f  7325 735b 2573 5d25 3634 7309 001b 5b30\n"
"0000201f  6d00 2573 5b25 735d 2573 0025 7325 7325\n" 
"0000202f  730a 0074 6578 7400 6469 7265 6374 6f72\n"
"0000203f  7900 2573 0063 6c65 6172 0025 7325 7325\n";

void print_options(const option_t* options_list, int size, const int selected) 
{
    char buffer[128];
    print_main_title();
    for (int i = 0; i < size; i++)
    {
        if (i == selected)
            snprintf(buffer, sizeof(buffer), "%s%s[%s]%64s\t", REVERSE, main_color, options_list[i].title, RESET);
        else
            snprintf(buffer, sizeof(buffer), "%s[%s]%s", main_color, options_list[i].title, RESET);
        puts(buffer);
    }
}

void set_main_title(const char* title)
{
    strncpy(main_title, title, 128);
}

void print_main_title(void)
{
    printf("%s%s%s\n", main_color, main_title, RESET);
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
    int i;
    int ch;
    i = -1;
    ch = getch();
    printf("%s", main_color);
    while (text[++i] != '\0')
    {   
        putchar(text[i]);
        fflush(stdout);
        usleep(delay * 500);
        if (ch == '\t')
        {
            system("clear");
            print_main_title();
            return;
        }
    }
    printf("%s", RESET);
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

void print_content(const option_t* option_list, const int size, const int selected)
{
    int ch;
    system("clear");
    print_main_title();
    if (strncmp(option_list[selected].content_type, "text", 4) == 0)
    {
        printf("%s%s%s\n", main_color, (char*)option_list[selected].content, RESET);
    }
    else if (strncmp(option_list[selected].content_type, "directory", 10) == 0)
    {
        if ((option_t*)option_list[selected].content == NULL)
        {
            printf("%s%-512s%s\n", RED, data_corrupted, RESET);
        }
        else
        {
            int size = 0;
            while ((option_t*)option_list[selected].content)
                size++;
            print_options((option_t*)option_list[selected].content, size, -1);
        }
    }
    while (ch = getch())
    {
        if (ch == '\t')
        {
            select_option(option_list, size);
            break;
        }
    }
}

void select_option(const option_t* options_list, const int size)
{
    int ch;
    int selected;
    selected = 0;

    system("clear");

    print_options(options_list, size, selected);
    while (ch = getch())
    {
        if (ch == 'q')
            exit(EXIT_SUCCESS);

        if (ch == '\n')
        {
            print_content(options_list, size, selected);
            break;
        }
        
        if (ch == '\033')
        {
            getch();   
            switch (getch())
            {
            case 'A':
                system("clear");
                selected--;
                if (selected < 0)
                    selected = size - 1;
                print_options(options_list, size, selected);
                break;
            
            case 'B':
                system("clear");
                selected++;
                if (selected >= size)
                    selected = 0;
                print_options(options_list, size, selected);
                break;
            default:
                break;
            }
        }
    }
}