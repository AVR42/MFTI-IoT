CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = temp_app
SOURCES = main.c temp_functions.c
HEADERS = temp_functions.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
