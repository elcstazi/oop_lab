#include "Player.h"


Player::Player() {
	primaryHealth = health = 6;
	coordinateX = 0;
	coordinateY = 0;
	numberKey = 0;
	//needNumberKeys = 10 + rand() % 11;
	needNumberKeys = 10;
	dead = false;
	playerInDoor = false;
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
	if (health >= 5)
		health = 6;
	else
		health++;
}


void Player::decreaseHealth() {
	health-=2;
	if (health <= 0) {
		health = 0;
		dead = true;
	}
}


void Player::increaseKey() {
	numberKey++;
}


void Player::decreaseKey() {
	if (numberKey!= 0) numberKey--;
}


bool Player::die() {
	return dead;
}


bool Player::win() {
	return playerInDoor;
}

void Player::setWin() {
	playerInDoor = true;
}
