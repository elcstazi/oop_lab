#include "FieldView.h"

FieldView::FieldView(Field* currentField) {
	cellView = 0;
	field = currentField;
	field->addFieldView(this);
}

void FieldView::update() {
	Sleep(10);
	system("cls");
	int width = field->getWidth();
	int height = field->getHeight();
	int currentX = field->getCurrentX(), currentY = field->getCurrentY();
	drawHorizontalBorder(width);
	for (int i = 0; i < height; ++i) {
		std::cout << '@';
		for (int j = 0; j < width; ++j) {
			if (currentX == j && currentY == i)
				std::cout << 'o';
			else
				cellView->draw(field->getMargin()[i][j]->getType());
		}
		std::cout << "@\n";

	}
	drawHorizontalBorder(width);


}

void FieldView::drawHorizontalBorder(int width) {
	for (int i = 0; i < width + 2; ++i) std::cout << '@';
	std::cout << '\n';
}
