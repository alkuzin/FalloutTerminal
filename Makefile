CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

NAME=libfterm.a

LIB_PATH=libfterm/

TERMINAL_PATH=$(LIB_PATH)/terminal/
LOGIN_PATH=$(LIB_PATH)/login/
UI_PATH=$(LIB_PATH)/ui/

OBJS = terminal.o login.o ui.o

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

terminal.o: $(TERMINAL_PATH)terminal.c
	$(CC) $(CFLAGS) -c $(TERMINAL_PATH)terminal.c

ui.o: $(UI_PATH)ui.c
	$(CC) $(CFLAGS) -c $(UI_PATH)ui.c

login.o: $(LOGIN_PATH)login.c
	$(CC) $(CFLAGS) -c $(LOGIN_PATH)login.c

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)
