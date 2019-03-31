#include "bird.h"
#include <sstream>

Bird::Bird()
{
	x = 96;
	y = 240;

	t.loadFromFile("assets/bird.png");
	s.setTexture(t);
	s.setOrigin(20, 15);		//referencia en el centro del sprite

	buffer.loadFromFile("assets/flap.wav");
	flap.setBuffer(buffer);
}

void Bird::fly() {
	if (alive == 1)
		flap.play();	//sonido
	
	dy = -2;			//vuela (sube en el eje y)
}

void Bird::update() {
	dy += 0.1; 			//gravedad
	
	if (dy<0) 
		angle = -30; 	//si subo cambia angulo (setRotation gira en el sentido del reloj)
	else 
		angle = 0; 		
	
	y += dy; 			//el pajaro cae
	checkHeight();

	s.setPosition(x, y);
	s.setRotation(angle);
}

void Bird::checkHeight() {		//comprueba altura
	if (y > 420) 				//game over si toca suelo
		alive = 0;
}

void Bird::reset() {
	y = 240; 	
	dy = 0;
	counter = 0; 
	alive = 1; 
}

void Bird::draw(sf::RenderWindow& win) {
	win.draw(s);
}

std::string Bird::getStrPoints() {
	std::ostringstream bo;		//buffer de salida
	bo << counter;				
	return bo.str();			//devuelve como string
}

float Bird::getX() {
	return x;
}

float Bird::getY() {
	return y;
}

int Bird::getCounter() {
	return counter;
}

bool Bird::isAlive() {
	return alive;
}

void Bird::setAlive(bool b) {
	alive = b;
}

void Bird::addCounter() {
	counter++;
}