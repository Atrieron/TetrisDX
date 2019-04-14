#pragma once
#include "../DrawingSystem.h"

class GameField
{
private:
	static int topX, topY;

	float squareWidth, squareHeight;
	bool* field;	
	int width, height;
public:
	void ClearField();
	void Draw(DrawingSystem* drawingSystem);
	GameField(int width, int height, float squareWidth, float squareHeight);
	~GameField();
	void ClearRows();

	bool getValue(int x, int y);
	void setValue(int x, int y, bool value);
	int getWidth();
	int getHeight();
};