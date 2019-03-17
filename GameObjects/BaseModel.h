#pragma once
#include "GameField.h"

class BaseModel
{
private:
	bool* field;
	int width, height;
	static BaseModel** figures;
	static void initFigures();
public:
	BaseModel();
	~BaseModel();
	static BaseModel* nextFigure();
	bool getValue(int x, int y);
	int getWidth();
	int getHeight();
};