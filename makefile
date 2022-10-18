main: main.cpp  Include/Drawable/Sound.cpp Include/State/ScoreState.cpp Include/Drawable/Button.cpp Include/Entity/Brute.cpp Include/Entity/Pilgrim.cpp Include/Entity/Viking.cpp Include/Entity/Golem.cpp Include/Entity/Entity.cpp Include/Entity/Player.cpp Include/Drawable/DynamicSprite.cpp Include/Drawable/Sprite.cpp Include/Drawable/Text.cpp Include/Instance/Game.cpp Include/State/PlayState.cpp Include/State/MenuState.cpp Include/State/State.cpp Include/State/PickState.cpp Include/State/MapState.cpp
	g++ main.cpp Include/Drawable/Sound.cpp Include/State/ScoreState.cpp Include/Drawable/Button.cpp Include/Entity/Brute.cpp Include/Entity/Pilgrim.cpp Include/Entity/Viking.cpp Include/Entity/Golem.cpp Include/Entity/Entity.cpp Include/Entity/Player.cpp Include/Drawable/DynamicSprite.cpp Include/Drawable/Sprite.cpp Include/Drawable/Text.cpp Include/Instance/Game.cpp Include/State/PlayState.cpp Include/State/MenuState.cpp Include/State/State.cpp Include/State/PickState.cpp Include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o main.out
	./main.out

mac: main.cpp  Include/Drawable/Sound.cpp Include/State/ScoreState.cpp Include/Drawable/Button.cpp Include/Entity/Brute.cpp Include/Entity/Pilgrim.cpp Include/Entity/Viking.cpp Include/Entity/Golem.cpp Include/Entity/Entity.cpp Include/Entity/Player.cpp Include/Drawable/DynamicSprite.cpp Include/Drawable/Sprite.cpp Include/Drawable/Text.cpp Include/Instance/Game.cpp Include/State/PlayStateMac.cpp Include/State/MenuState.cpp Include/State/State.cpp Include/State/PickState.cpp Include/State/MapState.cpp
	g++ main.cpp Include/Drawable/Sound.cpp Include/State/ScoreState.cpp Include/Drawable/Button.cpp Include/Entity/Brute.cpp Include/Entity/Pilgrim.cpp Include/Entity/Viking.cpp Include/Entity/Golem.cpp Include/Entity/Entity.cpp Include/Entity/Player.cpp Include/Drawable/DynamicSprite.cpp Include/Drawable/Sprite.cpp Include/Drawable/Text.cpp Include/Instance/Game.cpp Include/State/PlayStateMac.cpp Include/State/MenuState.cpp Include/State/State.cpp Include/State/PickState.cpp Include/State/MapState.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o main.out
	./main.out

text: Tests/Drawable/TextTest.cpp Include/Drawable/Text.cpp
	g++ Tests/Drawable/TextTest.cpp Include/Drawable/Text.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o TextTest.out
	clear
	./TextTest.out

sprite: Tests/Drawable/SpriteTest.cpp Include/Drawable/Sprite.cpp
	g++ Tests/Drawable/SpriteTest.cpp Include/Drawable/Sprite.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o SpriteTest.out
	clear
	./SpriteTest.out

dSprite: Tests/Drawable/DynamicSpriteTest.cpp Include/Drawable/DynamicSprite.cpp Include/Drawable/Sprite.cpp
	g++ Tests/Drawable/DynamicSpriteTest.cpp Include/Drawable/DynamicSprite.cpp Include/Drawable/Sprite.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o DynamicSpriteTest.out
	clear
	./DynamicSpriteTest.out

entityStats: Tests/Entity/EntityStatsTest.cpp Include/Entity/Entity.cpp Include/Drawable/Sprite.cpp Include/Drawable/DynamicSprite.cpp
	g++ Tests/Entity/EntityStatsTest.cpp  Include/Entity/Entity.cpp Include/Drawable/Sprite.cpp Include/Drawable/DynamicSprite.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 -o DynamicSpriteTest.out
	clear
	./DynamicSpriteTest.out

clean:
	rm *.out