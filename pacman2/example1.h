
#include "pch.h"
#include <iostream>

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
using namespace std;
using namespace sf;
class Example1 {
	

public : 
	bool  keyPressed(Keyboard::Key keybord) {
		return Keyboard::isKeyPressed(keybord);
	}
	Example1() {
		RenderWindow window(VideoMode(500, 500), "SFML works!");
		window.setFramerateLimit(60);

		// Circle
		CircleShape circle(20.f);
		circle.setFillColor(Color(105, 189, 107));
		circle.setOutlineThickness(2.f);
		circle.setOutlineColor(Color::Blue);




		// Rectangler
		RectangleShape rect(Vector2f(100.f, 50.f));
		rect.setPosition(100, 200);
		rect.setFillColor(Color(24, 26, 171));

		// Triangle
		CircleShape triangle(50.f);
		triangle.setPointCount(3);
		//triangle.setPointCount(6);  // 3shan t3mel shakl  sodasy 



		// Draw a Line

		Vertex line[] = { Vertex(Vector2f(10.f , 10.f)) ,  Vertex(Vector2f(100.f , 100.f)) };






		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			if (keyPressed(Keyboard::Escape)) {
				window.close();
			}

			circle.move(.5f, .5f);
			rect.move(-.5f, -.5f);
			rect.rotate(1);

			window.clear(Color(246, 104, 73)); // you have to clear the winow every time to draw new frame 
			window.draw(circle);
			window.draw(rect);
			window.draw(triangle);
			window.draw(line, 2, Lines); // draw a line 
			window.display();
		}
	}


};
