#include "Field.h"
#include "Cell.h"
#include "Types.h"

Field::Field(int newHeight, int newWidth) : player(new Player()) {
	height = newHeight < 15 ? 20 : newHeight;
	width = newWidth < 15 ? 35 : newWidth;


	int y, x, key = 10;
	int wall = (height * width) / 4;
	int countHeal = (height * width) * (3.0 / 4) / 15;
	int countTrapDamage = (height * width) * (3.0 / 4) / 17;


	Card_initialization();
	//addCellKey(key);
	//addCellDoor();
	//addCellWall(wall);
	//addCellHeal(countHeal);
	//addCellTrapDamage(countTrapDamage);
	//addCellMapChange();

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




int Field::getHeight() {
	return height;
}


int Field::getWidth() {
	return width;
}


std::vector<std::vector<Cell*>> Field::getMargin() {
	return margin;
}


int& Field::getCurrentX() {
	return player->getX();
}


int& Field::getCurrentY() {
	return player->getY();
}


void Field::updatePlayer(Player* currentPlayer) {
	player = currentPlayer;
}


//void Field::addCellWall(int count) {
//	int x, y;
//	while (count > 0) {
//		y = (height + (rand() - rand()) % height) % height;
//		x = (width + (rand() - rand()) % width) % width;
//		if (margin[y][x]->getType() == SIMPLEPASSABLE && player->getY() != y && player->getX() != x) {
//			margin[y][x]->setType(IMPASSABLE);
//			count--;
//		}
//	}
//}
//
//
//void Field::addCellDoor() {
//	int x, y;
//	do {
//		y = (height + (rand() - rand()) % height) % height;
//		x = (rand() + rand()) % width;
//	} while (getMargin()[y][x]->getType() != SIMPLEPASSABLE && player->getY() != y && player->getX() != x);
//
//	getMargin()[y][x]->setType(CELL_DOOR);
//	getMargin()[y][x]->setEvent(new Door());
//}
//
//
//void Field::addCellKey(int count) {
//	int x, y;
//	while (count > 0) {
//		y = (height + (rand() - rand()) % height) % height;
//		x = (width + (rand() - rand()) % width) % width;
//		if (margin[y][x]->getType() == SIMPLEPASSABLE && player->getY() != y && player->getX() != x) {
//			margin[y][x]->setType(CELL_KEY);
//			margin[y][x]->setEvent(new Key());
//			count--;
//		}
//
//	}
//}
//
//
//void Field::addCellHeal(int count) {
//	int x, y;
//	while (count > 0) {
//		y = (height + (rand() - rand()) % height) % height;
//		x = (width + (rand() - rand()) % width) % width;
//		if (margin[y][x]->getType() == SIMPLEPASSABLE && player->getX() != x && player->getY() != y) {
//			margin[y][x]->setType(HEAL);
//			margin[y][x]->setEvent(new Heal());
//			count--;
//		}
//	}
//}
//
//void Field::addCellTrapDamage(int count) {
//	int x, y;
//	while (count > 0) {
//		y = (height + (rand() - rand()) % height) % height;
//		x = (width + (rand() - rand()) % width) % width;
//		if (margin[y][x]->getType() == SIMPLEPASSABLE && player->getX() != x && player->getY() != y) {
//			margin[y][x]->setType(TRAPDAMAGE);
//			margin[y][x]->setEvent(new TrapDamage());
//			count--;
//		}
//	}
//}
//
//void Field::addCellMapChange() {
//	for (int i = 0; i < height; ++i) {
//		for (int j = 0; j < width; ++j) {
//			if (margin[i][j]->getType() == SIMPLEPASSABLE && player->getY() != i && player->getX() != j) {
//				margin[i][j]->setType(MAPCHANGE);
//				margin[i][j]->setEvent(new MapChange());
//			}
//		}
//	}
//}

void Field::Card_initialization(){

	margin = std::vector<std::vector<Cell*>>(height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			margin[i].push_back(new Cell());
		}
	}
}

std::pair<int, int> Field::find_empty_cell()
{
	int y = (height + (rand() - rand()) % height) % height;
	int x = (width + (rand() - rand()) % width) % width;
	while (true) {
		if (margin[y][x]->getType() == SIMPLEPASSABLE && !(player->getY() == y && player->getX() == x))
			return std::pair<int, int>(y, x);
		y = (height + (rand() - rand()) % height) % height;
		x = (width + (rand() - rand()) % width) % width;
	}
}
