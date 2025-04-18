all: temp_stats

temp_stats: main.o temp_functions.o
	$(CC) -o temp_stats main.o temp_functions.o

main.o: main.c temp_functions.h
	$(CC) -c main.c

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) -c temp_functions.c

clean:
	rm -f *.o temp_stats
