CFLAGS = -Wall -Wextra -pedantic -g
LIBS = -lSDL2 -lSDL2_ttf -lSDL2_mixer -lm
SRC = ./src/main.cpp
DEST = main

all:
	g++ $(CFLAGS) -o $(DEST) $(SRC) $(LIBS)

clean:
	rm -f $(DEST)
