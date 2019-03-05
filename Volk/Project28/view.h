#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

View view;
void getPlayerCoordinateforView(float x, float y) {
	float tempX = x; float tempY = y;
	if (x <= 300) { tempX = 300; }
	if (y <= 450) { tempY = 450; }
	if (y >= 1470) { tempY = 1470; }
	if (x >= 3340) { tempX = 3340; }
	view.setCenter(tempX+ 100, tempY);
}