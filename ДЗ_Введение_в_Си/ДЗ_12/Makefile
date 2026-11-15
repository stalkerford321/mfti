TARGET = temp_app
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lmingwex 

SOURCES = main.c temp_api.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.c temp_api.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJECTS) $(TARGET).exe

.PHONY: all clean