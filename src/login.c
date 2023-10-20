#include "../include/login.h"

static int attempts = MAX_ATTEMPTS;
char login_title[TITLE_SIZE] = 
"ROBCO INDUSTRIES (TM) TERMLINK PROTOCOL\n";

int login(void)
{
    int num = 32636;
    char password[INPUT_SIZE];
    char failed_attempt[25 + INPUT_SIZE + 1] = " ";
    
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
        for(int i = 0; i < 16; i++)
        {
            printf("0x%04x ............ 0x%04x ............ \n", num, num + 24);
            num += 12;
        }
        num = 32636;
        printf("0x%04x ............ 0x%04x ......USER-$ > ", num, num + 24);
        
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
