#include "Player.h"


Player::Player() {
	primaryHealth = health = 6;
	coordinateX = 0;
	coordinateY = 0;
	numberKey = 0;
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
	if (getHealth() != getPrimaryHealth()) {
		health++;
		Notify("The player's health has increased", "Player", INFO);
	}
}


void Player::decreaseHealth() {
	
	Notify("The player's health has decreased", "Player", INFO);

	if (health > 2) {
		health -= 2;
	}
	else {
		health = 0;
		dead = true;
		Notify("The player dies", "Player", INFO);
	}
}


void Player::increaseKey() {
	numberKey++;
	Notify("Increasing the number of player keys", "Player", INFO);
}


void Player::decreaseKey() {
	if (numberKey != 0) numberKey--;
}


bool Player::die() {
	return dead;
}


bool& Player::getPlayerInDoor() {
	return playerInDoor;
}