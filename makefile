CC = gcc
CFLAGS = -Wno-implicit-function-declaration

TARGET_PATH=src/

final: main.o terminal.o
	@echo "(*) Linking and producting the final application"
	$(CC) $(CFLAGS) terminal.o main.o -o terminal
	chmod +x terminal
	@echo "[+] Complete successfully"

main.o: $(TARGET_PATH)main.c
	@echo "(*) Compiling program file"
	$(CC) $(CFLAGS) -c $(TARGET_PATH)main.c

terminal.o: $(TARGET_PATH)terminal.c
	@echo "(*) Compiling terminal.c"
	$(CC) $(CFLAGS) -c $(TARGET_PATH)terminal.c

clean:
	@echo "(*) Removing extra files"
	rm main.o terminal.o