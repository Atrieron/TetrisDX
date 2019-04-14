#include "Tetris.h"

void Tetris::Init()
{
	pGameField = new GameField(10, 20);
	pFigure = new Figure(0.4f, 0.4f);

	moveRate = 1000;
	fastMoveRate = 200;
	lastDrop = 0;
}

void Tetris::Update(DWORD tick)
{
	lastDrop += tick;
	int curMoveRate = downPressed ? fastMoveRate : moveRate;
	int updateCount = lastDrop / curMoveRate;

	for (int i = 0; i < updateCount; ++i) {
		pFigure->move(0, 1);
		HitCheckResult hitCheckResult = pFigure->CheckHit(pGameField);
		if (hitCheckResult.downHit)
		{
			pFigure->move(0, -1);
			pFigure->Paste(pGameField, true);
			pFigure->Reset();

			pGameField->ClearRows();

			hitCheckResult = pFigure->CheckHit(pGameField);
			if (hitCheckResult.downHit)
			{
				pGameField->ClearField();
			}
		}
	}

	lastDrop -= updateCount*curMoveRate;
}

void Tetris::Draw(ID3D11DeviceContext* pImmediateContext, ID3D11Buffer*	pVariableBuffer)
{
	pGameField->Draw(pImmediateContext, pVariableBuffer);
	pFigure->Draw(pImmediateContext, pVariableBuffer);
}

void Tetris::UpButton()
{
	pFigure->Rotate(false);
	HitCheckResult hitCheckResult = pFigure->CheckHit(pGameField);
	while (hitCheckResult.downHit)
	{
		pFigure->move(0, -1);

		if (hitCheckResult.leftHit)
			pFigure->move(1, 0);

		if (hitCheckResult.rightHit)
			pFigure->move(-1, 0);

		hitCheckResult = pFigure->CheckHit(pGameField);
	}

	while (hitCheckResult.leftHit)
	{
		pFigure->move(1, 0);
		hitCheckResult = pFigure->CheckHit(pGameField);
	}

	while (hitCheckResult.rightHit)
	{
		pFigure->move(-1, 0);
		hitCheckResult = pFigure->CheckHit(pGameField);
	}
}

void Tetris::LeftButton()
{
	pFigure->move(-1, 0);
	HitCheckResult hitCheckResult = pFigure->CheckHit(pGameField);
	if (hitCheckResult.leftHit || hitCheckResult.downHit)
	{
		pFigure->move(1, 0);
	}
}

void Tetris::RigtButton()
{
	pFigure->move(1, 0);
	HitCheckResult hitCheckResult = pFigure->CheckHit(pGameField);
	if (hitCheckResult.rightHit || hitCheckResult.downHit)
	{
		pFigure->move(-1, 0);
	}
}

void Tetris::PressDownButton()
{
	downPressed = true;
}

void Tetris::ReleaseDownButton()
{
	downPressed = false;
}

Tetris::Tetris()
{
}

Tetris::~Tetris()
{
}