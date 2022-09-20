main: main.cpp Game.cpp Gameplay.cpp MenuState.cpp
	g++ main.cpp Game.cpp Gameplay.cpp MenuState.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main.out
	./main.out