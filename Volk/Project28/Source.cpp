#include <SFML/Graphics.hpp>
#include<iostream>
#include "Map.h"
#include "view.h"
using namespace sf;

class Player{
private:
	float x, y;
public:
	float  w, h, dx, dy, speed=0;
	int dir=0;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String F, float X, float Y, float W, float H) {
		//image.loadFromFile("images/"+File);
		texture.loadFromFile(F);
		sprite.setTexture(texture);
		w = W; h = H;
		x = X; y = Y;
		sprite.setTextureRect(IntRect(49, 130, w, h));
	}
	void update(float time) {
		switch (dir) {

		case 0:dx = speed; dy = 0; break;
		case 1:dx = -speed; dy = 0; break;
		case 2:dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}
		x += dx * time;
		y +=dy * time;
		speed = 0;
		sprite.setPosition(x, y);
	}
	float getPlayerCoordinateX() {	
		return x;
	}
	float getPlayerCoordinateY() {	
		return y;
	}

};
int main()
{

	RenderWindow window(VideoMode(1600, 900), "Volk");
	view.reset(sf::FloatRect(0, 0, 1600, 900));
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	Player Hero("images/hero.png", 100, 100, 49, 65);
	Clock clock;
	float CurrentFrame = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/600;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			Hero.dir = 1;
			Hero.speed = 0.1;
			Hero.sprite.setTextureRect(IntRect(49*int(CurrentFrame), 65, 49, 65)); }
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			CurrentFrame += 0.005*time;
			Hero.dir = 0;
			Hero.speed = 0.1;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			Hero.sprite.setTextureRect(IntRect(49*int(CurrentFrame), 130, 49, 65)); }
		if (Keyboard::isKeyPressed(Keyboard::W)) { 
			CurrentFrame += 0.005*time;
			Hero.dir = 3;
			Hero.speed = 0.1;
			if (CurrentFrame > 4) CurrentFrame -= 4; 
			Hero.sprite.setTextureRect(IntRect(49 * int(CurrentFrame), 195, 49, 65)); }
		if (Keyboard::isKeyPressed(Keyboard::S)) { 
			CurrentFrame += 0.005*time;
			Hero.dir = 2;
			Hero.speed = 0.1;
			if (CurrentFrame > 4) CurrentFrame -= 4; 
			Hero.sprite.setTextureRect(IntRect(49 * int(CurrentFrame), 0, 49, 65)); }
		getPlayerCoordinateforView(Hero.getPlayerCoordinateX(), Hero.getPlayerCoordinateY());
		Hero.update(time);
		window.setView(view);
		window.clear();
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(64, 320,64,64));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(0, 128, 64, 64));
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(64, 32, 64, 64));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 32, 64, 64));

				s_map.setPosition(j * 64, i * 64);

				window.draw(s_map);
			}
		window.draw(Hero.sprite);
		
		window.display();
	}
	return 0;
}