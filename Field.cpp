#include "Field.h"
#include "Cell.h"
#include "Types.h"

Field::Field(int height, int width) : player(new Player()), height(height), width(width), numberKey(20) {
	
	int max = height < width ? width : height;
	key = (int)(max / 4) + rand() % 3;
	elixir = 1 + rand() % 3;
	margin = std::vector<std::vector<Cell*>>(height);

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int res = rand();
			if (i == 0 && j == 0) margin[i].push_back(new Cell());
			else if (key > 0 && res % 20 == 0) { key--; margin[i].push_back(new Cell(SIMPLEPASSABLE, 1)); }
			else if (elixir > 0 && res % 25 == 0) { elixir--; margin[i].push_back(new Cell(SIMPLEPASSABLE, 2 + rand()%2));}
			else if (res % 29 == 0) { margin[i].push_back(new Cell(IMPASSABLE, 5)); }
			else margin[i].push_back(new Cell());
		}
	}
}

Field::Field() : Field(20, 20) {}

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

int Field::getCurrentX() {
	return player->getX();
}

int Field::getCurrentY() {
	return player->getY();
}

void Field::setCurrentY(int currentY) {
	player->getY() = currentY;
	//---------------------------------------------------------------------------------------------------------
	notifyUpdate();
}

void Field::setCurrentX(int currentX) {
	player->getX() = currentX;
	//---------------------------------------------------------------------------------------------------------
	notifyUpdate();
}


std::vector<std::vector<Cell*>> Field::getMargin() {
	return margin;
}

void Field::updatePlayer(Player* currentPlayer) {
	player = currentPlayer;
}

void Field::addKey() {
	int flag = 1, xKey, yKey;
	while (flag) {
		xKey = rand() % width;
		yKey = rand() % height;
		if (xKey != getCurrentX() && yKey != getCurrentY()) {
			if (margin[yKey][xKey]->getFree() == SIMPLEPASSABLE && margin[yKey][xKey]->getType() == 4) {
				delete margin[yKey][xKey];
				margin[yKey][xKey] = new Cell(SIMPLEPASSABLE, 1);
				flag = 0;
			}
		}
	}
	//---------------------------------------------------------------------------------------------------------
	notifyUpdate();

}

void Field::addDoor() {
	int flag = 1, xKey, yKey;
	while (flag) {
		xKey = rand() % width;
		yKey = rand() % height;
		if (xKey != getCurrentX() && yKey != getCurrentY()) {
			if (margin[yKey][xKey]->getFree() == SIMPLEPASSABLE && margin[yKey][xKey]->getType() == 4) {
				delete margin[yKey][xKey];
				margin[yKey][xKey] = new Cell(SIMPLEPASSABLE, 0);
				flag = 0;
			}
		}
	}
	//---------------------------------------------------------------------------------------------------------
	notifyUpdate();
}

int Field::getNumberKeys() {
	
	return numberKey;
}

int& Field::getNumberDoor() {
	
	return numberDoor;
}
//---------------------------------------------------------------------------

void Field::addFieldView(FieldView* fieldView) {
	consoleView = fieldView;
}

void Field::notifyUpdate() {
	consoleView->backGroundDraw();
}