TARGET = report
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lmingwex # Для getopt в MinGW

SOURCES = report.c temp_functions.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.c temp_functions.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJECTS) $(TARGET).exe

.PHONY: all clean