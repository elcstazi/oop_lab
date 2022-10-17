#include "Player.h"


Player::Player(int type) {
	this->type = type;
	primaryHealth = health = 5;
	stength = 0;
	coordinateX = 0;
	coordinateY = 0;
	numberKey = 0;
	needNumberKeys = 10 + rand() % 11;
	//needNumberKeys = 1;
	alive = true;
}


int& Player::getX() {

	return coordinateX;
}


int& Player::getY() {

	return coordinateY;
}


int Player::getHealth() {
	return health;
}


int Player::getPrimaryHealth() {
	return primaryHealth;
}


int& Player::getNumberKey() {
	return numberKey;
}


int& Player::getNeedNumberKeys() {
	return needNumberKeys;
}


void Player::increaseHeath() {
	if (health >= 4) 
		health = 5;
	else
		health++;
}	


void Player::decreaseHealth() {
	health--;
	if (health <= 0) {
		health = 0;
		alive = false;
	}
}


void Player::increaseKey() {
	numberKey++;
}


void Player::decreaseKey() {
	numberKey--;
}


bool Player::die() {
	return !alive;
}
