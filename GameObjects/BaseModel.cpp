#include "BaseModel.h"

BaseModel::BaseModel()
{
}

BaseModel::~BaseModel()
{
}

int squareCoordsToFlat(int x, int y, int width)
{
	return width*y + x;
}

BaseModel* BaseModel::nextFigure()
{
	if (!figures)
		BaseModel::initFigures();
	
	return figures[rand()%7];
}

bool BaseModel::getValue(int x, int y)
{
	auto coords = squareCoordsToFlat(x, y, width);
	return field[coords];
}

int BaseModel::getWidth()
{
	return width;
}

int BaseModel::getHeight()
{
	return height;
}

void BaseModel::initFigures()
{
	figures = new BaseModel*[7];

	figures[0] = new BaseModel();
	figures[0]->height = 2;
	figures[0]->width = 3;
	
	figures[0]->field = new bool[6];
	figures[0]->field[0] = true;
	figures[0]->field[1] = false;
	figures[0]->field[2] = false;
	figures[0]->field[3] = true;
	figures[0]->field[4] = true;
	figures[0]->field[5] = true;

	figures[1] = new BaseModel();
	figures[1]->height = 2;
	figures[1]->width = 3;

	figures[1]->field = new bool[6];
	figures[1]->field[0] = false;
	figures[1]->field[1] = false;
	figures[1]->field[2] = true;
	figures[1]->field[3] = true;
	figures[1]->field[4] = true;
	figures[1]->field[5] = true;

	figures[2] = new BaseModel();
	figures[2]->height = 2;
	figures[2]->width = 3;
	
	figures[2]->field = new bool[6];
	figures[2]->field[0] = false;
	figures[2]->field[1] = true;
	figures[2]->field[2] = true;
	figures[2]->field[3] = true;
	figures[2]->field[4] = true;
	figures[2]->field[5] = false;

	figures[3] = new BaseModel();
	figures[3]->height = 2;
	figures[3]->width = 3;
	
	figures[3]->field = new bool[6];
	figures[3]->field[0] = true;
	figures[3]->field[1] = true;
	figures[3]->field[2] = false;
	figures[3]->field[3] = false;
	figures[3]->field[4] = true;
	figures[3]->field[5] = true;

	figures[4] = new BaseModel();
	figures[4]->height = 2;
	figures[4]->width = 3;

	figures[4]->field = new bool[6];
	figures[4]->field[0] = false;
	figures[4]->field[1] = true;
	figures[4]->field[2] = false;
	figures[4]->field[3] = true;
	figures[4]->field[4] = true;
	figures[4]->field[5] = true;

	figures[5] = new BaseModel();
	figures[5]->height = 2;
	figures[5]->width = 2;

	figures[5]->field = new bool[4];
	figures[5]->field[0] = true;
	figures[5]->field[1] = true;
	figures[5]->field[2] = true;
	figures[5]->field[3] = true;

	figures[6] = new BaseModel();
	figures[6]->height = 1;
	figures[6]->width = 4;

	figures[6]->field = new bool[4];
	figures[6]->field[0] = true;
	figures[6]->field[1] = true;
	figures[6]->field[2] = true;
	figures[6]->field[3] = true;
}

BaseModel** BaseModel::figures = NULL;