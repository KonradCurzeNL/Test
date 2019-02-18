#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 400), "SFMLworks");

	Image heroimage;
	heroimage.loadFromFile("images/hero.png");

	Texture herotexture;
	herotexture.loadFromImage(heroimage);
	//herotexture.loadFromFile("images\\hero.png");
	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 130, 49, 65));
	herosprite.setPosition(20, 30);
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
			herosprite.move(-0.1*time, 0); 
			herosprite.setTextureRect(IntRect(49*int(CurrentFrame), 65, 49, 65)); }
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			herosprite.move(0.1*time, 0); 
			herosprite.setTextureRect(IntRect(49*int(CurrentFrame), 130, 49, 65)); }
		if (Keyboard::isKeyPressed(Keyboard::W)) { 
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			herosprite.move(0, -0.1*time); 
			herosprite.setTextureRect(IntRect(49 * int(CurrentFrame), 195, 49, 65)); }
		if (Keyboard::isKeyPressed(Keyboard::S)) { 
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			herosprite.move(0, 0.1*time); 
			herosprite.setTextureRect(IntRect(49 * int(CurrentFrame), 0, 49, 65)); }
		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}