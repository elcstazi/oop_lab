#include "FieldView.h"

FieldView::FieldView(Field* field) {

	this->field = field;
	field->addFieldView(this);
}

void FieldView::backGroundDraw() {
	Sleep(50);
	system("cls");
	int width = field->getWidth();
	int height = field->getHeight();
	drawHorizontalBorder(width);
	for (int i = 0; i < height; ++i) {
		std::cout << '@';
		for (int j = 0; j < width; ++j) {
			if (field->getCurrentX() == j && field->getCurrentY() == i)
				std::cout << 'o';
			else
				cellView->draw(field->getMargin()[i][j]->getFree(), field->getMargin()[i][j]->getType());
		}
		std::cout << "@\n";

	}
	drawHorizontalBorder(width);
}

void FieldView::drawHorizontalBorder(int width) {
	for (int i = 0; i < width + 2; ++i) std::cout << '@';
	std::cout << '\n';
}
