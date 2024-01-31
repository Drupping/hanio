CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -std=c11
LDFLAGS =

SRCS = hanoi.c utils.c
OBJS = $(SRCS:.c=.o)
TARGET = hanoi

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
