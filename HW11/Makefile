CC = gcc
CFLAGS = -Wall -Wextra

all: temp_app

temp_app: main.o temp_api.o
	$(CC) $(CFLAGS) -o temp_app main.o temp_api.o

main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c temp_api.c

clean:
	rm -f *.o temp_app
