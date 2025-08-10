CC = gcc
SRC_DIR = src
INCLUDE_DIR = includes
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)
TARGET = alphavim

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

.PHONY: all clean
