
CC=gcc
OBJS=Question1.o Question2.o main.o
EXEC=game
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c Question1.h Question2.h
Question1.o: Question1.c Question1.h
Question2.o: Question2.c Question2.h




clean: 
	rm -f $(EXEC) $(OBJS)
	
