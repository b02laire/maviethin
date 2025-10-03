CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -O3
TARGET  = chess_engine
SRCS    = board.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c board.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
