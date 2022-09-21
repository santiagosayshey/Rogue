main: main.cpp Game.cpp Gameplay.cpp MenuState.cpp GameState.cpp
	g++ main.cpp Game.cpp Gameplay.cpp MenuState.cpp GameState.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main.out
	clear
	./main.out