#include "pch.h"
#include <iostream>

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"packman.h"

using namespace std;
using namespace sf;
class Example2 {

public:
	bool keyPressed(Keyboard::Key keybord) {
		return Keyboard::isKeyPressed(keybord);
	}

	Example2() {
		RenderWindow window(sf::VideoMode(500, 500), "SFML works!");


		RectangleShape rect(Vector2f(100.f,20.f));
		rect.setPosition(Vector2f(200.f, 100.f));
		PackMan object = PackMan();

		


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

		
				object.listen();



			if (object.getGlobalBounds().intersects(rect.getGlobalBounds()))
				object.setPosition(Vector2f(200.f, 200.f));

			if(object.getPosition().x <= 0 || object.getPosition().y <= 0)
				object.setPosition(Vector2f(200.f, 200.f));

			else if (object.getPosition().x >= window.getSize().x || object.getPosition().y >= window.getSize().y)
				object.setPosition(Vector2f(200.f, 200.f));

			window.clear();
			window.draw(object);
			window.draw(rect);
			window.display();
		}

	}


};