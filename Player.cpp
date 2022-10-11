#include "Player.h"


Player::Player(int type){
	this->type = type;
	health = 100;
	stength = 0;
	coordinateX = 0;
	coordinateY = 0;
	numberKey = 0;
	alive = true;
}


int& Player::getX() {

	return coordinateX;
}


int& Player::getY() {

	return coordinateY;
}


int Player::gethealth() {
	return health;
}


int Player::getNumberKey() {
	return numberKey;
}


void Player::increaseHeath() {
	if (health >= 3) 
		health = 4;
	else
		health++;
}	


void Player::decreaseHealth() {
	health--;
	if (health == 0)
		alive = false;
}


void Player::increaseKey() {
	numberKey++;
}


bool Player::die() {
	return alive;
}