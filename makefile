CC = gcc
CFLAGS = -Wno-implicit-function-declaration

final: main.o terminal.o
	@echo "(*) Linking and producting the final application"
	$(CC) $(CFLAGS) terminal.o main.o -o terminal
	chmod +x terminal
	@echo "[+] Complete successfully"

main.o: main.c
	@echo "(*) Compiling program file"
	$(CC) $(CFLAGS) -c main.c

terminal.o: terminal.c
	@echo "(*) Compiling terminal.c"
	$(CC) $(CFLAGS) -c terminal.c

clean:
	@echo "(*) Removing extra files"
	rm main.o terminal.o
