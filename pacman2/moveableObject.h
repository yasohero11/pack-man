#include "pch.h"
#include <iostream>

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"

using namespace sf;
using namespace std;


class  MoveableObject:public Sprite   {

private:
	float defultXStrps = 0.0;
	float defultYStrps = 0.0;
	float XSteps = 0.0;
	float YSteps = 0.0;
	bool num1Pressed = false;
	bool num2Pressed = false;
	
	
	
public:
	float dt;
	Clock dt_clock;
	Vector2f velocity;
	Texture image;

	MoveableObject(float XSteps, float YSteps, float width, float hight , string imageName ) {
		loadImage(image,imageName);
		
		setTexture(image);
		setScale(Vector2f(width, hight));

		this->XSteps = XSteps;
		this->YSteps = YSteps;
		defultYStrps = YSteps;
		defultXStrps = XSteps;
	}
	MoveableObject(float width, float hight, string imageName) :MoveableObject(0.1f, 0.1f, width, hight, imageName){}

	bool keyPressed(Keyboard::Key keybord) {
		return Keyboard::isKeyPressed(keybord);
	}

	void loadImage(Texture &texture, string imageName) {
		if (!texture.loadFromFile("res/" + imageName + ".png"))
			throw "the image didn't load";
	}
	

	void slow(float percentage) {
		if (!num1Pressed) {
			float percent = percentage / 100;
			XSteps = defultXStrps - (defultXStrps * percent);
			YSteps = defultYStrps - (defultYStrps * percent);
			cout << XSteps << endl;
			
			num2Pressed = false;
			num1Pressed = true;
		}
	}

	void fast(float percentage) {
		if (!num2Pressed) {
			float percent = percentage / 100;
			XSteps = defultXStrps + (defultXStrps * percent);
			YSteps = defultYStrps + (defultYStrps * percent);
			cout << XSteps << endl;
			
			num1Pressed = false;
			num2Pressed = true;
		}
	}
	void defultSpeed() {
		XSteps = defultXStrps;
		YSteps = defultYStrps;
	}

	void moveUp() {
		move(0.f, -YSteps);
		velocity.y += -YSteps*2;
	}
	void moveDown() {
		move(0.f, YSteps);
		velocity.y += YSteps *2;
	}

	void moveRight() {
		 move(XSteps, 0.f);
		 velocity.x += XSteps * 2;
	}
	void moveLeft() {
		
		move(-XSteps, 0.f);
	}

	



};