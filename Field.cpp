#include "Field.h"
#include "Cell.h"
#include "Types.h"

Field::Field(int newHeight, int newWidth) : player(new Player()) {
	height = newHeight < 15 ? 15 : newHeight;
	width = newWidth < 15 ? 15 : newWidth;
	countKey = 7;


	int y, x, key = countKey;
	int wall = 2 * (height + width);


	maxCountTrapLoseKey = (height * width - wall - key) / 40;
	currentCountTrapLoseKey = 0;


	maxCountTrapDamage = player->getPrimaryHealth() + 2;
	currentCountTrapDamage = 0;

	maxCountHeal =  2 * player->getHealth();
 	currentCountHeal = 0;

	margin = std::vector<std::vector<Cell*>>(height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			margin[i].push_back(new Cell());
		}
	}

	while (key > 0) {
		y = (rand()+ rand()) % height;
		x = (width + (rand() - rand()) % width)% width;
		if (margin[y][x]->getType() == SIMPLEPASSABLE && player->getX() != x && player->getY() != y) {
			margin[y][x]->setType(KEY);
			key--;
		}
			
	}

	while (wall > 0) {
		y = (height + (rand() - rand()) % height) % height;
		x = (rand() + rand()) % width;
		if (margin[y][x]->getType() == SIMPLEPASSABLE && player->getX() != x && player->getY() != y) {
			margin[y][x]->setType(IMPASSABLE);
			wall--;
		}
	}

	//while (countTrapLoseKey > 0) {
	//	y = (height + (rand() - rand()) % height) % height;
	//	x = (rand() + rand()) % width;
	//	if (margin[y][x]->getType() == SIMPLEPASSABLE && player->getX() != x && player->getY() != y) {
	//		margin[y][x]->setType(TRAPLOSEKEY);
	//		countTrapLoseKey--;
	//	}
	//}
}


Field::Field() : Field(20, 35) {}


Field::~Field() {
	for (auto row : margin) {
		for (auto col : row) delete col;
	}
	player = nullptr;
}


Field::Field(const Field& other) {
	this->player = other.player;
	this->height = other.height;
	this->width = other.width;
	this->margin = std::vector<std::vector<Cell*>>(other.height);
	for (int i = 0; i < other.height; ++i) {
		this->margin[i] = std::vector<Cell*>(other.width);
		for (int j = 0; j < other.width; ++j) {
			this->margin[i][j] = other.margin[i][j];
		}

	}
}

Field& Field::operator=(const Field& other) {
	if (this == &other) return *this;

	for (auto row : this->margin) {
		for (auto col : row) delete col;
	}
	this->player = other.player;
	this->height = other.height;
	this->width = other.width;
	this->margin = std::vector<std::vector<Cell*>>(other.height);
	for (int i = 0; i < other.height; ++i) {
		this->margin[i] = std::vector<Cell*>(other.width);
		for (int j = 0; j < other.width; ++j) {
			this->margin[i][j] = other.margin[i][j];
		}

	}

	return *this;
}

Field::Field(Field&& other) {
	this->player = other.player;
	this->height = other.height;
	this->width = other.width;
	this->margin = other.margin;
	other.margin = std::vector <std::vector <Cell*>>();

}

Field& Field::operator=(Field&& other) {
	if (this == &other) return *this;

	this->player = other.player;
	this->height = other.height;
	this->width = other.width;
	for (auto row : margin) {
		for (auto col : row) delete col;
	}
	this->margin = other.margin;
	other.margin = std::vector < std::vector <Cell*>>();

	return *this;
}



void Field::addFieldView(FieldView* consoleView) {
	fieldView = consoleView;
}


void Field::notifyUpdate() {
	fieldView->update();
}


int Field::getHeight() {
	return height;
}


int Field::getWidth() {
	return width;
}


std::vector<std::vector<Cell*>> Field::getMargin() {
	return margin;
}


int Field::getCurrentX() {
	return player->getX();
}


int Field::getCurrentY() {
	return player->getY();
}

//-----------------------------------------------------------
//void Field::setCurrentY(int currentY) {
//	player->getY() = currentY;
//	notifyUpdate();
//}
//
//
//void Field::setCurrentX(int currentX) {
//	player->getX() = currentX;
//	notifyUpdate();
//}
//-----------------------------------------------------------

void Field::updatePlayer(Player* currentPlayer) {
	player = currentPlayer;
}

int& Field::getKey() {
	return countKey;
}


int Field::getMaxCountTrapLoseKey() {
	return maxCountTrapLoseKey;
}


int& Field::getCurrentCountTrapLoseKey() {
	return currentCountTrapLoseKey;
}


int Field::getMaxCountTrapDamage() {
	return maxCountTrapDamage;
}


int& Field::getCurrentCountTrapDamage() {
	return currentCountTrapDamage;
}


int Field::getMaxCountHeal() {
	return maxCountHeal;
}


int& Field::getCurrentCountHeal() {
	return currentCountHeal;
}