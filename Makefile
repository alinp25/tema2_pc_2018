CC = gcc
CFLAGS = -Wall -Wextra 
NCURSESFLAGS = -lncurses -lmenu

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

build: $(OBJ)
	$(CC) -g -o trivia $(OBJ) $(NCURSESFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -g

run: build
	./trivia Questions.txt Questions2.txt && reset 

clean:
	rm -rf *.o && rm ./trivia

rebuild: clean build
