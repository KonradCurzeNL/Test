#pragma once
#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 30;
const int WIDTH_MAP = 60;
int hmap = HEIGHT_MAP * 64;
int wmap = WIDTH_MAP * 64;
sf::String TileMap[HEIGHT_MAP] = {
	"000000000000000000000000000000000000000000000000000000000000",
	"0             0ff                                          0",
	"0     s       0                                            0",
	"0     s       0                                            0",
	"0             0                                            0",
	"0             0        ffffffff                            0",
	"0             0           ssss                             0",
	"0             0                                            0",
	"000000000000000                                            0",
	"0          s                                               0",
	"0         s     s                                          0",
	"0        s      s       s       s        sss               0",
	"0       s        s       s                                 0",
	"0      s          s        ssss        s      s            0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"000000000000000000000000000000000000000000000000000000000000",
	
};
