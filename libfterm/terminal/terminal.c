/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   terminal.c                                                               */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/26 08:54:28 by alkuzin                                  */
/*   Updated: 2023/12/28 12:48:14 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static char title[TITLE_SIZE];
static char option[OPTION_SIZE];
static void* parent_window = DEFAULT_PARENT_WINDOW;
int field_width = DEFAULT_FIELD_WIDTH;

// selected option index
static int selected = 0;

// listen keys from keyboard
static int getch(void);

/* set terminal parent window */
static void set_parent_window(option_t* options_list);

/* print option content */
static void print_content(option_t* option_list, const int size);


void init_terminal(option_t *options_list, int size)
{
	slow_print(title, DEFAULT_DELAY);
    set_parent_window(options_list);
    select_option(options_list, size);
}

void hide_cursor(void)
{
    printf("%s", "\e[?25l"); 
}

void show_cursor(void)
{
    printf("%s", "\e[?25h"); 
}

void set_title(const char *new_title)
{
    strncpy(title, new_title, TITLE_SIZE);
}

void set_field_width(int width)
{
    field_width = width;
}

void set_option_content(option_t* option, void* content)
{
    switch(option->content_type)
    {
        case TEXT:
            option->content = (char *) content;
            break;
    
        case ERROR:
            option->content = (char *) content;
            break;
    
        case DIRECTORY:
            option->content = (option_t*) content;
            break;

        default:
            option->content = NULL;
            break;
    }        
}

void set_option_content_type(option_t* option, int content_type)
{
    option->content_type = content_type;
}

void print_options(const option_t* options_list, int size) 
{   
    print_col(title);
    for (int i = 0; i < size; i++)
    {
        snprintf(option, OPTION_SIZE, "[%s]%*s\t", options_list[i].title, 
                (int)(field_width - strlen(options_list[i].title) - 1), " ");
        if (i == selected)
            print_rev_col(option);
        else
        {
            change_col(primary_color);
            puts(option);
            reset_color();
        }
            
    }
}

void select_option(option_t* options_list, const int size)
{
    int ch;
    system("clear");

    print_options(options_list, size);
    while ((ch = getch()))
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

void slow_print(const char* text, int delay)
{
    int i;


	i = -1;
	change_col(primary_color);
    while (text[++i] != '\0')
    {   
        putchar(text[i]);
        fflush(stdout);
        usleep(delay * 500);
    }
    reset_color();
}

static int getch(void) 
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

static void print_content(option_t* option_list, const int size)
{
    int ch;
    system("clear");
    print_col(title);

    if (option_list[selected].content == NULL)
    {
        set_option_content(&option_list[selected], "--ERROR MISSING DATA--");
        set_option_content_type(&option_list[selected], ERROR);
    }

    switch (option_list[selected].content_type)
    {
    case TEXT:
        print_col((char*)option_list[selected].content);
        break;

    case DIRECTORY:
        system("clear");
        int temp_selected = selected;
        selected = 0;
        select_option((option_t*)option_list[temp_selected].content, 2);
        selected = 0;
        break;

    case ERROR:
        print_err_col((char*)option_list[selected].content);
        break;
    
    default:
        print_err_col("--UNKNOWN CONTENT TYPE--");
        break;
    }
    while ((ch = getch()))
    {
        if (ch == '\t')
        {
            select_option(option_list, size);
            break;
        }
    }
}

static void set_parent_window(option_t* options_list)
{
    parent_window = options_list;
}
