#include "GameField.h"

int _squareCoordsToFlat(int x, int y, int width)
{
	return width*y + x;
}

void GameField::ClearField()
{
	for (int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
			field[_squareCoordsToFlat(x, y, width)] = false;
}

GameField::GameField(int width, int height, float squareWidth, float squareHeight)
{
	this->width = width;
	this->height = height;

	this->squareWidth = squareWidth;
	this->squareHeight = squareHeight;

	field = new bool[width*height];

	ClearField();
}

GameField::~GameField()
{
}

void GameField::ClearRows()
{
	int bottomLevel = height - 1;
	while (bottomLevel > -1) {
		bool needClear = true;
		bool isEmpty = true;
		for (int i = 0; i < width; ++i) {
			if (field[_squareCoordsToFlat(i, bottomLevel, width)]) {
				isEmpty = false;
			} else {
				needClear = false;
			}

			if (!isEmpty && !needClear) {
				break;
			}
		}

		if (isEmpty) {
			break;
		} else {
			if (needClear) {
				for (int j = bottomLevel; j > 0; --j) {
					for (int i = 0; i < width; ++i) {
						field[_squareCoordsToFlat(i, j, width)] = field[_squareCoordsToFlat(i, j - 1, width)];
					}
				}

				for (int i = 0; i < width; ++i) {
					field[i] = false;
				}
			} else {
				--bottomLevel;
			}
		}
	}
}

bool GameField::getValue(int x, int y)
{
	return field[_squareCoordsToFlat(x, y, width)];
}

void GameField::setValue(int x, int y, bool value)
{
	field[_squareCoordsToFlat(x, y, width)] = value;
}

int GameField::getWidth()
{
	return width;
}

int GameField::getHeight()
{
	return height;
}

void GameField::Draw(DrawingSystem * drawingSystem)
{
	for (int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
		{
			drawingSystem->drawSquare(topX + squareWidth*x, topY - squareHeight*y, squareWidth, squareHeight, 0.8f, 0.8f, 0.8f);
			if (field[_squareCoordsToFlat(x, y, width)])
				drawingSystem->drawSquare(topX + squareWidth*x, topY - squareHeight*y, squareWidth * 0.9f, squareHeight * 0.9f, 0.0f, 0.8f, 0.0f);
			else
				drawingSystem->drawSquare(topX + squareWidth*x, topY - squareHeight*y, squareWidth * 0.9f, squareHeight * 0.9f, 0.0f, 0.0f, 0.0f);
		}
}

int GameField::topX = -9.0f;
int GameField::topY = 5.0f;