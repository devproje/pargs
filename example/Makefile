include ../config.mk

SRC_DIR = .
LIB_DIR = ../dist
INCLUDE_DIR = ..

SAMPLE_SRCS = sample.c
SAMPLE_OBJS = $(SAMPLE_SRCS:.c=.o)
LIB = $(LIB_DIR)/pargs.a

TARGET = sample.out

CC = gcc
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

all: $(TARGET)

$(TARGET): $(SAMPLE_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(SAMPLE_OBJS)
	rm -f $(TARGET)

.PHONY: all clean
