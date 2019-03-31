#include "scene.h"
#include "bird.h"
#include "pipe.h"

Scene::Scene(Bird& b, Pipe& p1, Pipe& p2, Pipe& p3, sf::Sound& c) 
	: bird(b), first(p1), second(p2), third(p3), coin(c) 
{

}

void Scene::checkCollision() {
	int current_obstacle_x;
	int current_obstacle_y;
	
	int right = bird.getX() + 20;		//limites del pajaro
	int top = bird.getY() - 15;
	int down = bird.getY() + 15;
	
	if (bird.getCounter() % 3 == 0) { 	//pipe actual (por donde va el pajaro) es multiplo de 3, uso score para calcular
		current_obstacle_x = first.getX(); 
		current_obstacle_y = first.getY(); 
	} 	
	if (bird.getCounter() % 3 == 1) { 
		current_obstacle_x = second.getX();; 
		current_obstacle_y = second.getY(); 
	}
	if (bird.getCounter() % 3 == 2) { 
		current_obstacle_x = third.getX(); 
		current_obstacle_y = third.getY(); 
	}
	
	if ( right > current_obstacle_x && 
		( top < 480-current_obstacle_y || down > (480+120)-current_obstacle_y) )
		bird.setAlive(false);
}

void Scene::checkSuccess() {
	for (auto i : { &first,&second,&third }) {		
		if (i->getX() == 5 && bird.isAlive() == 1) {		//si el pajaro supera el pipe (el origen del pipe llega a x=5)
			bird.addCounter();
			coin.play();
		}
	}
}