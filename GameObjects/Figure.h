#pragma once
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
	static XMFLOAT4 vBackColor, vFilledColor;
	static int topX, topY;

	int x, y;
	float squareWidth, squareHeight;
	unsigned short orientation;

	bool* field;
	int width, height;

	void setupField(int number);
public:
	Figure(float squareWidth, float squareHeight);
	~Figure();
	void Reset();
	void Rotate(bool backward);
	void move(int dx, int dy);
	HitCheckResult CheckHit(GameField* gameField);
	void Paste(GameField* gameField, bool value);
	void Draw(ID3D11DeviceContext* pImmediateContext, ID3D11Buffer* pVariableBuffer);
};