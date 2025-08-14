# Compiler and flags
CC = g++
CFLAGS = $(shell pkg-config --cflags sdl2) -Iinclude
LDFLAGS = $(shell pkg-config --libs sdl2)

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/boundrycheck.cpp \
      $(SRC_DIR)/player.cpp \
	  $(SRC_DIR)/drawRect.cpp \
	  $(SRC_DIR)/drawsky.cpp \
	  $(SRC_DIR)/update.cpp \
	  $(SRC_DIR)/initialise.cpp \
	  $(SRC_DIR)/fpscap.cpp

# Output binary
OUT = $(BUILD_DIR)/app.exe

# Default build target
build: $(SRC)
	mkdir $(BUILD_DIR)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

# Run the program
run: build
	./$(OUT)

# Clean the binary
clean: 
	rmdir /s /q build

cleanbuild: $(SRC)
	rmdir /s /q build
	mkdir $(BUILD_DIR)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)