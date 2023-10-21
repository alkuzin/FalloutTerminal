// =============================================================================
//
//    src/login.c	
//
//    By: alkuzin < >                                                     	
//
//    Updated: 21/10/2023 21:52:43                                             	
//
//                       Copyright "FalloutTerminal" (c), 2023.	
//
// =============================================================================
#include "../include/login.h"

static int attempts = MAX_ATTEMPTS;
char login_title[TITLE_SIZE] = 
"ROBCO INDUSTRIES (TM) TERMLINK PROTOCOL\n";

static char* memory_dump[STRING_ROWS * STRING_SIZE + 1] = 
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
        printf("%s%sENTER PASSWORD NOW\n\n", primary_color, login_title);
        printf("%d Attempt(s) left:", attempts);

        for (int i = 0; i < attempts; i++)
        {
            putchar(' ');
            putchar('#');
        }
        putchar('\n');
        putchar('\n');
        printf("%-64s\n\n", failed_attempt);
        
        temp_hexnumber = hexnumber;
        for(int i = 1; i < STRING_ROWS; i++)
        {
            printf("0x%04x %s 0x%04x %s \n", temp_hexnumber, memory_dump[2*(i-1)] , temp_hexnumber + 24, memory_dump[2*i-1]);
            temp_hexnumber += STRING_SIZE;
        }
        
        temp_hexnumber = hexnumber;
        printf("0x%04x .*]{}?$[] ]* 0x%04x -^{/)-USER-$ > ", temp_hexnumber, temp_hexnumber + 24);
        
        getinput(password);
        if ((strncmp(password, PASSWORD, PASSWORD_SIZE) == 0) && (strlen(password) == PASSWORD_SIZE))
            return 1;
        snprintf(failed_attempt, 25 + INPUT_SIZE + 1, "INCORRECT PASSWORD: '%s'", password);

        if (attempts == 0)
            break;
        --attempts;
    }   
    return 0;
}

void getinput(char* buffer)
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

void lock_out_terminal(void)
{
    hide_cursor();
    slow_print(
        "\n\n\n\n\n\t\t\t\t TERMINAL LOCKED\n"
        "\t\t\t\tPLEASE CONTACT AN\n"
        "\t\t\t\t  ADMINISTRATOR", DEFAULT_DELAY
    );
    puts_blink_col("\n\n\n\t\t\t   [press <enter> to continue]\n\n\n\n\n\n\n\n");
    getchar();
    show_cursor();
    exit(EXIT_FAILURE);
}

void set_login_title(char* new_title)
{
    strncpy(login_title, new_title, TITLE_SIZE);
}

int randint(int lower_range, int upper_range)
{
    srand(time(NULL));
    return rand() % (upper_range - lower_range + 1) + lower_range;
}