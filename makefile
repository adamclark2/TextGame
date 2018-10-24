CC=gcc

all: build build/text_game.o

run: all
	./build/text_game.o

clean:
	rm -rf build

build:
	mkdir build

build/text_game.o: src/text_game.c src/asset_manager.c
	$(CC) -o build/text_game.o src/text_game.c