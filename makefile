CC = g++
CFLAGS = $(shell pkg-config --cflags sdl2)
LDFLAGS = $(shell pkg-config --libs sdl2)

build: main.cpp
	$(CC) main.cpp -o app.exe $(CFLAGS) $(LDFLAGS)
r:
	./app.exe
c:
	rm ./*.exe
