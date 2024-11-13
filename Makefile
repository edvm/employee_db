CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main
OBJS = main.o db.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c db.h
	$(CC) $(CFLAGS) -c main.c

db.o: db.c db.h
	$(CC) $(CFLAGS) -c db.c

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean