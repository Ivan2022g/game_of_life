CC = gcc
CFLAGS = -Werror -Wall -Wextra
BUILD_DIR = build
TARGET = game
SRC = game_of_life.c

all: game

game: $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD)/$(TARGET) $(SRC) 