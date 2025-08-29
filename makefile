# Compiler and flags
CC = g++
CFLAGS = $(shell pkg-config --cflags sdl2) -Iinclude
# Manually specify linker flags WITHOUT -mwindows
LDFLAGS = -lmingw32 -lSDL2main -lSDL2

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files (explicitly listed)
SRC = $(SRC_DIR)/*.cpp
     
# Output binary
OUT = $(BUILD_DIR)/app.exe

# Default build target
build: $(OUT)

$(OUT): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

run: build
	./$(OUT)

clean:
	rm -rf $(BUILD_DIR)
