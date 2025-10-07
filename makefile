# ---- Makefile ----
CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -O2 -Iinclude
LDFLAGS =

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = crypto

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f src/*.o $(BIN)
# -------------------
