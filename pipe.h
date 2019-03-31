#ifndef __PIPE_H__
#define __PIPE_H__

#include <SFML/Graphics.hpp>

class Pipe {
public:
	Pipe(int pos_x);
	void update();
	void reset();
	void draw(sf::RenderWindow& win);
	int getX();
	int getY();

private:
	sf::Texture t1, t2; 
	sf::Sprite s_up, s_down;
	int x;
	int y; 
	int ini_x;
};

#endif