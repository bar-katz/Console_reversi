#
#

a.out: Game.o GameFlow.o Cell.o Player.o HumanPlayer.o Board.o main.o
	g++ Game.o GameFlow.o Cell.o Player.o HumanPlayer.o Board.o main.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

GameFlow.o: GameFlow.cpp GameFlow.h
	g++ -c GameFlow.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	g++ -c HumanPlayer.cpp

main.o: main.cpp GameFlow.o
	g++ -c main.cpp

clean:
	rm -f *.o a.out
