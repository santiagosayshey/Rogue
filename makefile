main: main.cpp  include/Drawable/Button.cpp include/Entity/Brute.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp
	g++ main.cpp include/Drawable/Button.cpp include/Entity/Brute.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o main.exe
	./main.exe

debug: main.cpp  include/Entity/Brute.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp
	g++ main.cpp include/Entity/Brute.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayState.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o main.exe
	./main.exe

mac: main.cpp  include/Entity/Brute.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayStateMac.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp
	g++ main.cpp include/Entity/Brute.cpp include/Entity/Pilgrim.cpp include/Entity/Viking.cpp include/Entity/Golem.cpp include/Entity/Entity.cpp include/Entity/Player.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp include/Drawable/Text.cpp include/Instance/Game.cpp include/State/PlayStateMac.cpp include/State/MenuState.cpp include/State/State.cpp include/State/PickState.cpp include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o main.app
	./main.app

TextTest: tests/Drawable/TextTest.cpp include/Drawable/Text.cpp
	g++ tests/Drawable/TextTest.cpp include/Drawable/Text.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o TextTest.out
	clear
	./TextTest.out

SpriteTest: tests/Drawable/SpriteTest.cpp include/Drawable/Sprite.cpp
	g++ tests/Drawable/SpriteTest.cpp include/Drawable/Sprite.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o SpriteTest.out
	clear
	./SpriteTest.out

DynamicSpriteTest: tests/Drawable/DynamicSpriteTest.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp
	g++ tests/Drawable/DynamicSpriteTest.cpp include/Drawable/DynamicSprite.cpp include/Drawable/Sprite.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o DynamicSpriteTest.out
	clear
	./DynamicSpriteTest.out

clean:
	rm *.app
	rm *.exe