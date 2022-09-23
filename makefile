main: main.cpp  include/Human.cpp include/Wizard.cpp include/Game.cpp include/PlayState.cpp include/MenuState.cpp include/State.cpp
	g++ main.cpp include/Human.cpp include/Wizard.cpp include/Button.cpp include/Game.cpp include/PlayState.cpp include/MenuState.cpp include/State.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main.out
	./main.out