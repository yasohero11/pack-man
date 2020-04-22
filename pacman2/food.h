
#include "pch.h"
#include <iostream>

#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"entity.h"
using namespace sf;
using namespace std;


class Food : public CircleShape {

private:
	SoundBuffer buffer;
	bool eated = false;
public:
	Sound sound;

	Food():CircleShape(8.f) {
		
		setFillColor(Color::Color(225, 70, 3));
		if (!buffer.loadFromFile("sound/food.wav"))
			cout << "can't load the sound";

		sound.setBuffer(buffer);
	}

	void setToEated() {

		sound.play();
		setRadius(0.f);
		eated = true;
		
	}
	bool isEated() {
		return eated;
	}
	
	bool inersectedWith(Sprite shape) {
		return this->getGlobalBounds().intersects(shape.getGlobalBounds());
	}
};