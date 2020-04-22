#include "pch.h"
#include <iostream>

#include"SFML\Graphics.hpp"


using namespace sf;

class Wall:public RectangleShape  {

public:
	
	Wall() {
		setSize(Vector2f(20.f, 20.f));
		setFillColor(Color::Blue);
	}

	bool inersectedWith(Sprite shape) {
		return this->getGlobalBounds().intersects(shape.getGlobalBounds());
	}



};