main: main.cpp Classes/Main.cpp
	g++ main.cpp Classes/Main.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main.out
	./main.out