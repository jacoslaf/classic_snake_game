main: main.cpp game.o snake.o
	g++ -o main main.cpp game.o snake.o -lncurses

game.o: game.cpp
	g++ -c game.cpp

snake.o: snake.cpp
	g++ -c snake.cpp
