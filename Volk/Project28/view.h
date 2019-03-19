#pragma once
#include <SFML/Graphics.hpp>
#include"Map.h"
using namespace sf;

View view;
void getPlayerCoordinateforView(float x, float y) {
	float tempX = x; float tempY = y;

	if (x <=800) { tempX = 800; }
	if (y <= 450) { tempY = 450; }
	if (y >= hmap-450) { tempY = hmap - 450; }
	if (x >= wmap-800) { tempX = wmap - 800; }
	view.setCenter(tempX, tempY);
}