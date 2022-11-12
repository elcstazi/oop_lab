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

Player::~Player(){
	for (auto cur : observers)
		delete cur;
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
	//if (health >= 5)
	//	health = 6;
	//else
	//	health++;
	if (getHealth() != getPrimaryHealth()) {
		health++;
		Notify("player health increase", "Player", INFO);
	}

}


void Player::decreaseHealth() {
	//health-=2;
	//if (health <= 0) {
	//	health = 0;
	//	dead = true;
	//}
	if (health <= 2) {
		health = 0;
		dead = true;
		Notify("A player has died", "Player", INFO);
	}
	else {
		health -= 2;
		Notify("player health decrease", "Player", INFO);
	}

}


void Player::increaseKey() {
	numberKey++;
	Notify("increase in the number of player keys", "Player", INFO);
}


void Player::decreaseKey() {
	if (numberKey!= 0) numberKey--;
}


bool Player::die() {
	return dead;
}

bool& Player::getPlayerInDoor(){
	return playerInDoor;
}





void Player::addObserver(Observer* observer) {
	observers.push_back(observer);
}