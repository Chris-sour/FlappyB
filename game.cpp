#include "game.h"

Game::Game() 
{
	win.create(sf::VideoMode(640, 480), "FlappyB (pulsa Espacio para volar)", sf::Style::Close);
	win.setFramerateLimit(60);
	win.setKeyRepeatEnabled(false);

	sf::Vector2i pos(300,150);
	win.setPosition(pos);
		
	buffer.loadFromFile("assets/coin.wav");
	coin.setBuffer(buffer); 
		
	font.loadFromFile("assets/arial.ttf");
	score.setFont(font); 
	score.setPosition(115, 15); 
	score.setCharacterSize(30);

	text_point.setFont(font);
	text_point.setPosition(10, 15);
	text_point.setCharacterSize(30);
	text_point.setString("Puntos: ");
	
	text_game_over.setFont(font); 
	text_game_over.setPosition(90, 200); 
	text_game_over.setCharacterSize(30);
	text_game_over.setString("Game Over (pulsa R para reiniciar)");
		
	t.loadFromFile("assets/background.png");
	background.setTexture(t);

	bird = new Bird();
	first = new Pipe(384);
	second = new Pipe(384+256);
	third = new Pipe(384+512);
	scene = new Scene(*bird, *first, *second, *third, coin);	

	music.openFromFile("assets/theme.ogg");
	music.setVolume(50);
	music.setLoop(true);
	music.play();
}

void Game::run() {				//bucle del juego
	while (win.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				win.close();
			if (e.type == sf::Event::KeyPressed)		
				if (e.key.code == sf::Keyboard::Escape)		
					win.close();
			if (e.type == sf::Event::KeyPressed)		
				if (e.key.code == sf::Keyboard::Space)
					bird->fly();
			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::R) {		
					for (auto i : { first,second,third }) 	
						i->reset();
					bird->reset(); 							
					music.play();
				}
			}
		}
		update();		
		draw();
	}
}

void Game::update() {		//comprueba colisiones y actualiza los elementos
	scene->checkCollision();	
	scene->checkSuccess();

	if (bird->isAlive()) {
		bird->update(); 
		for (auto i : { first,second,third }) 
			i->update();
	} 
}

void Game::draw() {		//borra la ventana, pinta cada elemento y refresca
	win.clear(); 

	win.draw(background);
	
	Pipe* arr[] = { first, second,third };
	for (auto i : arr) 
		i->draw(win);
	
	bird->draw(win);	
	win.draw(text_point);
	score.setString(bird->getStrPoints());
	win.draw(score);
	
	if (!bird->isAlive()) {
		win.draw(text_game_over);
		music.pause();
	}

	win.display();
}

Game::~Game() {
	delete scene;
	delete third;
	delete second;
	delete first;
	delete bird;
}