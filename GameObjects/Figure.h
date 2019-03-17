#pragma once
#include "BaseModel.h"
#include "GameField.h"

struct HitCheckResult
{
	bool downHit;
	bool leftHit;
	bool rightHit;
};

class Figure
{
private:
	int x, y;
	BaseModel* model;
	unsigned short orientation;
public:
	Figure();
	~Figure();
	void Reset();
	void Rotate();
	void move(int dx, int dy);
	HitCheckResult CheckHit(GameField* gameField);
	void Paste(GameField* gameField, bool value);
};