main: main.cpp include/Game.cpp include/PlayState.cpp include/MenuState.cpp include/State.cpp
	g++ main.cpp include/Game.cpp include/PlayState.cpp include/MenuState.cpp include/State.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main.out
	./main.out