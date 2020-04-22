#include "pch.h"
#include <iostream>

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"


#include"packman.h"
#include"wall.h"
#include"food.h"


using namespace sf;


bool keyPressed(Keyboard::Key keybord) {
	return Keyboard::isKeyPressed(keybord);
}

string game[] = {
	
	"ww ww wwwwwwwwwwwwwwww ww wwwwwwwwwwwwwwww ww wwwwwwwwwwwwwwww ww ww",
	"ww oo oooooooooooooooo oo oooooooooooooooo oo oooooooooooooooo oF ww",
	"ww oF FFFFFFFFFFFFFFFF oF FFFFFFFFFFFFFFFF oF FFFFFFFFFFFFFFFF oF ww",
	"ww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF ww",
	"ww oo oooooooooooooooo oo oooooooooooooooo oo oooooooooooooooo oF ww",
	"ww oF FFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFF oF ww",
	"ww oF wwwwwwwwwwwwwwww ww wwwwwwwwwwwwwwww ww wwwwwwwwwwwwwwww oF ww",
	"ww oF wFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFw oF ww",
	"ww oF wwwwwwwwwwwwwwww ww wwwwwwwwwwwwwwww ww wwwwwwwwwwwwwwww oF ww",
	"ww oo oooooooooooooooo oo oooooooooooooooo oo oooooooooooooooo oF ww",
	"ww oF FFFFFFFFFFFFFFFF oF FFFFFFFFFFFFFFFF oF FFFFFFFFFFFFFFFF oF ww",
	"ww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF wFFFFFFFFFFFFFFw oF ww",
	"ww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF wwwwwwwwwwwwwwww oF ww",
	"ww oo oooooooooooooooo oo oooooooooooooooo oo oooooooooooooooo oF ww",
	"ww FF FFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFF FF FFFFFFFFFFFFFFFF FF ww",
	"ww ww wwwwwwwwwwwwwwww ww wwwwwwFFFwwwwwww ww wwwwwwwwwwwwwwww ww ww",
	"FF FF FFFFFFFFFFFFFFFF FF FFFFwwFFFwwFFFFF FF FFFFFFFFFFFFFFFF FF FF",
	"FF FF FFFFFFFFFFFFFFFF FF FFFFwwFFFwwFFFFF FF FFFFFFFFFFFFFFFF FF FF",
	
};

bool isAllFoodDone(vector<Food> foods) {
	for (auto &food : foods) {
		if (!food.isEated())
			return false;
	}
	return true;
}
string getNumOfEatedFood(vector<Food> foods) {
	int num = 0;
	for (auto &food : foods) 
		if (food.isEated())
		     	num++;
	
	
	return to_string(num);
}
void main()
{
	RenderWindow window(VideoMode(1200, 700), "SFML works!");
	window.setFramerateLimit(60);
	bool winSoundPlyed = false;
	SoundBuffer buffer;
	Sound sound;
	SoundBuffer winBuffer;
	Sound winSound;
	Font font;
	
	
	if(!font.loadFromFile("fonts/Natural.ttf"))
		cout << "can't load the font";
	if (!buffer.loadFromFile("sound/food.wav"))
		cout << "can't load the sound";
	if (!winBuffer.loadFromFile("sound/win.wav"))
		cout << "can't load the sound";

	Text text("Score : 0", font);
	text.setCharacterSize(50);
	text.setStyle(Text::Bold);
	text.setFillColor(Color::Red);
	text.setPosition(Vector2f(window.getSize().x-300, window.getSize().y - 100));

	sound.setBuffer(buffer);
	sound.setVolume(20.f);
	winSound.setBuffer(winBuffer);
	winSound.setVolume(70.f);
	
	vector<Wall>walls;
	vector<Food>foods;
	Food food = Food();
	
	PackMan packman = PackMan();
	packman.setPosition(Vector2f(580.f, 600.f));
	
	
	
	for (auto &str : game) {
		for (auto myChar : str) {
			if (myChar == 'w') {
				walls.push_back(Wall());
			}
			else if (myChar == 'o') {
				foods.push_back(Food());
			}
		}
	}
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		
		packman.listen();
		
		
		packman.resetBlockedState();
		for (auto &wall : walls) {
			
			if (wall.inersectedWith(packman)) {
				packman.setBlockedState();
				
			}
			
		}

	for (auto &food : foods) {
		if (food.inersectedWith(packman)) {
			food.setToEated();
			sound.play();
			
			text.setString("Score :" +getNumOfEatedFood(foods));
		}
		}
	if (isAllFoodDone(foods)) {
		
		if (!winSoundPlyed) {
			packman.sound.stop();
			winSound.play();
			winSoundPlyed = true;
			text.setFillColor(Color::Yellow);
			text.setString("Score : You Win !" );
		}
	}
	
	


		window.clear();

		int count = 0;
		int wallNum = 0;
		int foodNum = 0;
		for (auto str : game) {
			float y = 20.f * count;
			float x = 0;
			count++;
			int count2 = 0;
			for (auto myChar : str) {
				if (myChar != ' ') {
					
					if (myChar == 'w') {

						window.draw(walls[wallNum]);
						walls[wallNum].setPosition(x, y);
						wallNum++;
						

					}
					else if(myChar == 'o') {
						window.draw(foods[foodNum]);
						foods[foodNum].setPosition(x+12.f, y+12.f);
						foodNum++;
						
					}
					count2++;
					x = 20.f * count2;
						

					
					
				}

			}

		}

		
		
		window.draw(packman);
		window.draw(text);
	
		
		window.display();
	}

	
}