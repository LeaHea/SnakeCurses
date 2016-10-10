worm.x: Screen.o getChar.o Worm.o Grid.o main.o
	g++ -ggdb -std=c++0x -o worm.x Screen.o getChar.o Worm.o Grid.o main.o -lcurses -ltermcap

test.o: test.cpp
	g++ -c -ggdb test.cpp -o test.o

Screen.o: Screen.cpp
	g++ -c -std=c++0x -ggdb Screen.cpp -o Screen.o

main.o: main.cpp
	g++ -c -ggdb main.cpp -o main.o

getChar.o: getChar.cpp 
	gcc -c -ggdb getChar.cpp -o getChar.o

Worm.o: Worm.cpp
	g++ -c -ggdb Worm.cpp -o Worm.o

Grid.o: Grid.cpp
	g++ -c -ggdb Grid.cpp -o Grid.o

clean:
	/bin/rm -f *.x *.o *~ *#
