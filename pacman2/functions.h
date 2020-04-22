
#include<iostream>

#include"SFML\Window.hpp"

using namespace sf;
class Functions {

public:

	static bool keyPressed(Keyboard::Key keybord) {
		return Keyboard::isKeyPressed(keybord);
	}

};