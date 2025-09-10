# Compiler and flags
CC = /opt/riscv/bin/riscv64-unknown-linux-gnu-gcc
CFLAGS = -Wall -O0

# Target program
TARGET = perf_test

# Source files
SRCS = perf_test.c perf.c

# Object files (derived from SRCS)
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile each .c into .o
%.o: %.c c908_events.h
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(OBJS) $(TARGET)
