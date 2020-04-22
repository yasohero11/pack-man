
#include "pch.h"
#include <iostream>

#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\System.hpp"

#include"moveableObject.h"

class PackMan :public MoveableObject {

private:
	string headState = "right";
	string blockedState;
	Texture headUp;
	Texture headDown;
	Texture headLeft;
	Texture headRight;
	SoundBuffer buffer;
	


public:
	Sound sound;

	PackMan() :MoveableObject(2.5f, 2.5f, .2f, .2f, "pacmanRight"){
		this->headRight = image;
		loadImage(headUp, "pacmanUp");
		loadImage(headDown, "pacmanDown");
		loadImage(headLeft, "pacmanLeft");	
		if (!buffer.loadFromFile("sound/pacman_chomp.wav"))
			cout << "can't load the sound";

		sound.setBuffer(buffer);
		sound.setLoop(true);
		sound.setVolume(10.f);
		sound.play();
		
	}
		
	

	bool checkHeadState(string state) {
		bool boolean = false;
		if (headState.compare(state) == 0) {
			boolean = true;
		}

		return boolean;
	}
	void moveUp(){
		if (blockedState.compare("up") != 0) {
			MoveableObject::moveUp();
			if (!checkHeadState("up")) {
				this->setTexture(headUp);
				headState = "up";
			}
		}
		else 
			move(0.f, 1.f);
			

	}
	void moveDown() {
		if (blockedState.compare("down") != 0) {
			MoveableObject::moveDown();
			if (!checkHeadState("down")) {
				this->setTexture(headDown);
				headState = "down";
			}
		}
		else 
			move(0.f, -1.f);
		
	}
	void moveRight() {
		if (blockedState.compare("right") != 0) {
			MoveableObject::moveRight();
			if (!checkHeadState("right")) {
				this->setTexture(headRight);
				headState = "right";
			}
		}
		else 
			move(-1.f, 0.f);
			
		
	}

	void moveLeft() {
		if (blockedState.compare("left") != 0) {
			MoveableObject::moveLeft();
			if (!checkHeadState("left")) {
				this->setTexture(headLeft);
				headState = "left";
			}
		}
		else 
			move(1.f, 0.f);
			
		
	}


	void listen() {
		
		
		if (keyPressed(Keyboard::A)) {
			moveLeft();
		}
		else if (keyPressed(Keyboard::D)) {
			moveRight();
		}
		else if (keyPressed(Keyboard::W)) {
			moveUp();
		}
		else if (keyPressed(Keyboard::S)) {
			moveDown();
		}
		else if (keyPressed(Keyboard::Num1)) {
			slow(70);
		}
		else if (keyPressed(Keyboard::Num2)) {
			fast(10);
		}
		else if (keyPressed(Keyboard::Num3)) {
			defultSpeed();
		}
		

	}

	void setBlockedState() {
		blockedState = headState;
		
	}
	void resetBlockedState() {
		blockedState = "";
	}




};