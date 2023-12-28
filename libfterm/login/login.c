/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   login.c                                                                  */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/25 21:54:58 by alkuzin                                  */
/*   Updated: 2023/12/28 15:43:51 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#include "login.h"
 
/* get string input from user*/
static void getinput(char* buffer);

/* get pseudorandom integer from lower_range to upper_range */
static int randint(int lower_range, int upper_range);

/* show number of attempts left */
static void show_attempts(char *failed_attempt);

/* check if password is correct */
static int is_correct(const char *password);

/* lock out terminal in case of loggin in failure */
static void lock_out_terminal(const char *lock_out_msg);

/* number of attempts */
static int attempts = MAX_ATTEMPTS;

char login_title[TITLE_SIZE]; 

static char *memory_dump[193] = 
{
"|?_}|[+=}|^!", "]+,,|[]+=||,", 
"&*@_]*[]!$ .", "-,{, | ^=,{ ", 
"&*_]/+|!{/?<", "-/^^{/^}!-^*", 
"-*/|.||[.}=*", ">+.[(^(_,-^^", 
"&*+}=?$+/.[<", ">.{.[//|]-+.", 
"-*.[$[||/}()", "&+[&}/)[^-+*",
")*=,,.|]/&//", "&^^+[/{[_--&",
".*^+{_|([]+(", ">)}_[]]{_-^&", 
".*]{}?$[] ]*", ")?{]+(&[+-^|", 
"^*)^)(|[]+=.", ")[^]?^+](-^_", 
".*{}[,|[.^)_", ">([]/=?]!-./", 
"&*]^?{|=){|-", "..(+/.+_&-._", 
"**[|)&$/}]_&", ".(_+{-[[}-._", 
"[*,[.}|?]/{@", "_/)${,]!+-^&", 
"$*]]].|![{^#", "*=[+(_]/]-^.", 
"$*+&.[|[_[+.", "*? ^+[}{[-^/"
};


int login(void)
{
    char password[INPUT_SIZE];
    char failed_attempt[25 + INPUT_SIZE + 1];   
    const int hexnumber = randint(32636, 65530);
    int temp_hexnumber;


    while (attempts >= 0)
    {
        system("clear");
		show_attempts(failed_attempt);
        
        temp_hexnumber = hexnumber;
        for(int i = 1; i < STRING_ROWS; i++)
        {
            printf("0x%04x %s 0x%04x %s \n", temp_hexnumber,
					memory_dump[2*(i-1)] , temp_hexnumber + 24, memory_dump[2*i-1]);
            temp_hexnumber += STRING_SIZE;
        }
        
        temp_hexnumber = hexnumber;
        printf("0x%04x .*]{}?$[] ]* 0x%04x -^{/)-USER-$ > ", temp_hexnumber, temp_hexnumber + 24);
        
        getinput(password);
		if(is_correct(password))
            return 1;
        
		snprintf(failed_attempt, 25 + INPUT_SIZE + 1, "INCORRECT PASSWORD: '%s'", password);

        if (attempts == 0)
            break;
        --attempts;
    }   
    return 0;
}

extern void login_success(const char *success_msg)
{
	hide_cursor();
    system("clear");
    
    print_col(get_login_title());
	slow_print(success_msg, DEFAULT_DELAY);

	print_blink_col("[press <enter> to continue]");
    getchar();
}

extern void login_failure(const char *failure_msg)
{
	system("clear");
    lock_out_terminal(failure_msg);
    reset_color();
}

static void lock_out_terminal(const char *lock_out_msg)
{
    hide_cursor();
    slow_print(lock_out_msg, DEFAULT_DELAY);
    print_blink_col("\n\n\n\t\t\t   [press <enter> to continue]\n\n\n\n\n\n\n\n");
    getchar();
    show_cursor();
    exit(EXIT_FAILURE);
}

void set_login_title(char* new_title)
{
    strncpy(login_title, new_title, TITLE_SIZE);
}

char *get_login_title(void)
{
    return login_title;
}

static void getinput(char* buffer)
{
    int i = 0;
    fgets(buffer, INPUT_SIZE, stdin);
    if (buffer)
    {
        while (buffer[i] != '\n' && buffer[i] != '\0')
            i++;
        if (buffer[i] == '\n')
            buffer[i] = '\0';
        else 
        {
            while (getchar() != '\n')
                continue;
        }
    }
}

static int randint(int lower_range, int upper_range)
{
    srand(time(NULL));
    return rand() % (upper_range - lower_range + 1) + lower_range;
}

static void show_attempts(char *failed_attempt)
{
    printf("\033[%dm%sENTER PASSWORD NOW\n\n", primary_color, login_title);
    printf("%d Attempt(s) left:", attempts);

    for (int i = 0; i < attempts; i++)
    {
        putchar(' ');
        putchar('#');
    }
    putchar('\n');
    putchar('\n');
    printf("%-64s\n\n", failed_attempt);
}

static int is_correct(const char *password)
{
	return ((strncmp(password, PASSWORD, PASSWORD_SIZE) == 0) && 
			(strlen(password) == PASSWORD_SIZE));
}
