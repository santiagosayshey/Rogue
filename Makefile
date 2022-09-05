main: main.cpp Headers/Window.cpp
	g++ main.cpp Headers/Window.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main.out
	./main.out