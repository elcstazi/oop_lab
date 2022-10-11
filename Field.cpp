#include "Field.h"
#include "Cell.h"
#include "Types.h"

Field::Field(int height, int width) : player(new Player()), height(height), width(width) {

	margin = std::vector<std::vector<Cell*>>(height);

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int res = rand();
			if (i == 0 && j == 0) margin[i].push_back(new Cell());
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



//-------------------------------------------------------
//void Field::addFieldView(FieldView* consoleView) {
//	fieldView = consoleView;
//}
//
//void Field::notifyUpdate() {
//	fieldView->backGroundDraw();
//}
//--------------------------------------------------------

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
	notifyUpdate();
}

void Field::setCurrentX(int currentX) {
	player->getX() = currentX;
	notifyUpdate();
}


std::vector<std::vector<Cell*>> Field::getMargin() {
	return margin;
}