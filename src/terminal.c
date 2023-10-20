// =============================================================================
//
//    src/terminal.c	
//
//    By: alkuzin < >                                                     	
//
//    Updated: 20/10/2023 17:17:43                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
#include "../include/terminal.h"

char title[TITLE_SIZE];
static char option[OPTION_SIZE];
static void* parent_window = NULL;
static int selected = 0; // selected option index

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

void hide_cursor(void)
{
    printf("%s", "\e[?25l"); 
}

void show_cursor(void)
{
    printf("%s", "\e[?25h"); 
}

void set_title(const char* new_title)
{
    strncpy(title, new_title, TITLE_SIZE);
}

void set_parent_window(option_t* options_list)
{
    parent_window = options_list;
}

void set_option_content(option_t* option, void* content)
{
    if (option->content_type == TEXT || option->content_type == ERROR)
        option->content = (char*) content;
    else if (option->content_type == DIRECTORY)
        option->content = (option_t*) content;
}

void set_option_content_type(option_t* option, int content_type)
{
    option->content_type = content_type;
}

void print_options(const option_t* options_list, int size) 
{   
    puts_col(title);
    for (int i = 0; i < size; i++)
    {
        snprintf(option, OPTION_SIZE, "[%s]%64s\t", options_list[i].title, " ");
        if (i == selected)
            puts_rev_col(option);
        else
            puts_col(option);
    }
}

void select_option(option_t* options_list, const int size)
{
    int ch;
    system("clear");

    print_options(options_list, size);
    while (ch = getch())
    {
        if (ch == 'q')
        {
            show_cursor();
            exit(EXIT_SUCCESS);
        }

        if (ch == '\n')
        {
            print_content(options_list, size);
            break;
        }

        if (ch == '\t')
        {
            if (parent_window != (void*)options_list)
                return;
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
                print_options(options_list, size);
                break;
            
            case 'B':
                system("clear");
                selected++;
                if (selected >= size)
                    selected = 0;
                print_options(options_list, size);
                break;
            default:
                break;
            }
        }
    }
}

void print_content(option_t* option_list, const int size)
{
    int ch;
    system("clear");
    puts_col(title);

    if (option_list[selected].content == NULL)
    {
        set_option_content(&option_list[selected], "--ERROR MISSING DATA--");
        set_option_content_type(&option_list[selected], ERROR);
    }

    switch (option_list[selected].content_type)
    {
    case TEXT:
        puts_col((char*)option_list[selected].content);
        break;

    case DIRECTORY:
        system("clear");
        int temp_selected = selected;
        selected = 0;
        select_option((option_t*)option_list[temp_selected].content, 2);
        selected = 0;
        break;

    case ERROR:
        puts_err_col((char*)option_list[selected].content);
        break;
    
    default:
        puts_err_col("--UNKNOWN CONTENT TYPE--");
        break;
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

void slow_print(const char* text, int delay)
{
    int i = -1;
    printf("%s", primary_color);
    while (text[++i] != '\0')
    {   
        putchar(text[i]);
        fflush(stdout);
        usleep(delay * 500);
    }
    printf("%s", COLOR_RESET);
}