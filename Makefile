CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

SRC_PATH=src/

final: main.o terminal.o ui.o login.o
	@echo "(*) Linking and producting the final application"
	$(CC) $(CFLAGS) main.o terminal.o ui.o login.o -o terminal
	chmod +x terminal
	@echo "[+] Complete successfully"

main.o: $(SRC_PATH)main.c
	@echo "(*) Compiling program file"
	$(CC) $(CFLAGS) -c $(SRC_PATH)main.c

terminal.o: $(SRC_PATH)terminal.c
	@echo "(*) Compiling terminal.c"
	$(CC) $(CFLAGS) -c $(SRC_PATH)terminal.c

ui.o: $(SRC_PATH)ui.c
	@echo "(*) Compiling ui.c"
	$(CC) $(CFLAGS) -c $(SRC_PATH)ui.c

login.o: $(SRC_PATH)login.c
	@echo "(*) Compiling login.c"
	$(CC) $(CFLAGS) -c $(SRC_PATH)login.c

clean:
	@echo "(*) Removing extra files"
	rm main.o terminal.o ui.o login.o
