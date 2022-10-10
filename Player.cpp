#include "Player.h"

Player::Player(int type) : type(type), health(100), coordinateX(0), coordinateY(0), numberKeys(0) {}

int& Player::getNamberKeys() {
	
	return numberKeys;
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
