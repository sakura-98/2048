2048.exe: game.o main.o run.o
	g++ *.o -o 2048.exe
game.o: game.hpp game.cpp
main.o: game.hpp run.hpp main.cpp
run.o: run.hpp run.cpp
clean:
	del *.o