#ifndef __BIRD_H__
#define __BIRD_H__

#include <SFML/Graphics.hpp>	
#include <SFML/Audio.hpp>		

class Bird {
public:
	Bird();
	void fly();
	void update();
	void checkHeight();
	void reset();
	void draw(sf::RenderWindow& win);
	std::string getStrPoints();
	float getX();
	float getY();
	int getCounter();
	bool isAlive();
	void setAlive(bool b);
	void addCounter();

private:
	sf::Texture t;
	sf::Sprite s;
	sf::SoundBuffer buffer;
	sf::Sound flap;
	float dy = 0;
	int angle = 0;
	bool alive = 1;
	int counter = 0;
	float x;		
	float y;
};

#endif