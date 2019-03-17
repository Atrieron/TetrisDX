#pragma once
#include <d3d11.h>
#include <xnamath.h>

class GameField
{
private:
	static XMFLOAT4 vBackColor, vEmptyColor, vFilledColor;
	static int topX, topY;

	bool* field;
	int width, height;
public:
	void ClearField();
	void Draw(ID3D11DeviceContext* pImmediateContext, ID3D11Buffer* pVariableBuffer);
	GameField(int width, int height);
	~GameField();
	bool getValue(int x, int y);
	void setValue(int x, int y, bool value);
	int getWidth();
	int getHeight();
};