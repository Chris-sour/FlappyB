#include "pipe.h"

Pipe::Pipe(int pos_x)
{
	t1.loadFromFile("assets/pipe_up.png");
	t2.loadFromFile("assets/pipe_down.png");
	
	s_up.setTexture(t1); 
	s_down.setTexture(t2); 

	srand(time(0));
	x = pos_x;
	y = rand()%240 + 210;
	ini_x = pos_x;
}

void Pipe::update() {
	x -= 1;				//se mueven hacia la izquierda

	if (x < -96) {		//al salir por la izquierda genera nuevas coordenadas para ella
		x = 640; 
		y = rand()%240 + 210;
	}

	s_up.setOrigin(0, y);
	s_up.setPosition(x, 0);
	s_down.setPosition(x, 600-y);
}

void Pipe::draw(sf::RenderWindow& win) {	//la ventana es quien pinta, la paso como parametro
	win.draw(s_up);
	win.draw(s_down);
}

void Pipe::reset() {
	x = ini_x;
	y = rand()%240 + 210;
}

int Pipe::getX() {
	return x;
}

int Pipe::getY() {
	return y;
}