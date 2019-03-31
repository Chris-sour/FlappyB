#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Audio.hpp>
class Bird;
class Pipe;

class Scene {
public:
	Scene(Bird& b, Pipe& p1, Pipe& p2, Pipe& p3, sf::Sound& c);
	void checkCollision();
	void checkSuccess();

private:
	Bird& bird;
	Pipe& first;
	Pipe& second; 
	Pipe& third;
	sf::Sound& coin;
};

#endif