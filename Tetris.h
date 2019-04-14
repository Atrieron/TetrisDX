#pragma once
#include "GameObjects\Figure.h"
#include "GameObjects\GameField.h"

class Tetris
{
private:
	bool downPressed;
	DWORD lastDrop;
	DWORD moveRate;
	DWORD fastMoveRate;

	GameField* pGameField;
	Figure*	pFigure;
public:
	void Init();
	void Update(DWORD tick);
	void Draw(ID3D11DeviceContext* pImmediateContext, ID3D11Buffer*	pVariableBuffer);
	void UpButton();
	void LeftButton();
	void RigtButton();
	void PressDownButton();
	void ReleaseDownButton();
	Tetris();
	~Tetris();
};

