#ifndef __GAME_H__
#define __GAME_H__

#include "bird.h"
#include "pipe.h"
#include "scene.h"

class Game {
public:
	Game();
	~Game();
	void run();
	void update();
	void draw();

private:
	sf::RenderWindow win;
	sf::Texture t;
	sf::Sprite background;
	sf::SoundBuffer buffer;
	sf::Sound coin;
	sf::Font font;
	sf::Text text_point;
	sf::Text score;
	sf::Text text_game_over;
	sf::Music music;
	Bird* bird;
	Pipe* first;
	Pipe* second;
	Pipe* third;
	Scene* scene;
};

#endif