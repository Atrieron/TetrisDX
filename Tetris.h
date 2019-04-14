#pragma once
#include "GameObjects\Figure.h"
#include "GameObjects\GameField.h"
#include "DrawingSystem.h"

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
	void Draw(DrawingSystem* drawingSystem);
	void UpButton();
	void LeftButton();
	void RigtButton();
	void PressDownButton();
	void ReleaseDownButton();
	Tetris();
	~Tetris();
};

