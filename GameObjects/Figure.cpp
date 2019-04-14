#include "Figure.h"

struct VariableBuffer
{
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};

int squareCoordsToFlat(int x, int y, int width)
{
	return width*y + x;
}

void Figure::setupField(int number)
{
	switch (number)
	{
	case 0: {
		height = 3;
		width = 3;

		field = new bool[9];
		field[0] = false;
		field[1] = false;
		field[2] = false;
		field[3] = true;
		field[4] = false;
		field[5] = false;
		field[6] = true;
		field[7] = true;
		field[8] = true;
		break;
	}
	case 1: {
		height = 3;
		width = 3;

		field = new bool[9];
		field[0] = false;
		field[1] = false;
		field[2] = false;
		field[3] = false;
		field[4] = false;
		field[5] = true;
		field[6] = true;
		field[7] = true;
		field[8] = true;
		break;
	}
	case 2: {
		height = 3;
		width = 3;

		field = new bool[9];
		field[0] = false;
		field[1] = false;
		field[2] = false;
		field[3] = false;
		field[4] = true;
		field[5] = true;
		field[6] = true;
		field[7] = true;
		field[8] = false;
		break;
	}
	case 3: {
		height = 3;
		width = 3;

		field = new bool[9];
		field[0] = false;
		field[1] = false;
		field[2] = false;
		field[3] = true;
		field[4] = true;
		field[5] = false;
		field[6] = false;
		field[7] = true;
		field[8] = true;
		break;
	}
	case 4: {
		height = 3;
		width = 3;

		field = new bool[9];
		field[0] = false;
		field[1] = false;
		field[2] = false;
		field[3] = false;
		field[4] = true;
		field[5] = false;
		field[6] = true;
		field[7] = true;
		field[8] = true;
		break;
	}
	case 5: {
		height = 2;
		width = 2;

		field = new bool[4];
		field[0] = true;
		field[1] = true;
		field[2] = true;
		field[3] = true;
		break;
	}
	case 6: {
		height = 4;
		width = 4;

		field = new bool[16];
		field[0] = false;
		field[1] = true;
		field[2] = false;
		field[3] = false;
		field[4] = false;
		field[5] = true;
		field[6] = false;
		field[7] = false;
		field[8] = false;
		field[9] = true;
		field[10] = false;
		field[11] = false;
		field[12] = false;
		field[13] = true;
		field[14] = false;
		field[15] = false;
		break;
	}
	}
}

Figure::Figure(float squareWidth, float squareHeight)
{
	this->squareWidth = squareWidth;
	this->squareHeight = squareHeight;
	Reset();
}

Figure::~Figure()
{
}

void Figure::Reset()
{
	setupField(rand() % 7);
	y = 0;
	x = 4;
	orientation = 0;
}

void Figure::Rotate(bool backward)
{
	bool b = false;
	for (int j = 0; j < height / 2; ++j)
	{
		for (int i = 0; i < width / 2; ++i) {
			if (backward)
			{
				b = field[squareCoordsToFlat(i, j, width)];
				field[squareCoordsToFlat(i, j, width)] = field[squareCoordsToFlat(height - j - 1, i, width)];
				field[squareCoordsToFlat(height - j - 1, i, width)] = field[squareCoordsToFlat(width - i - 1, height - j - 1, width)];
				field[squareCoordsToFlat(width - i - 1, height - j - 1, width)] = field[squareCoordsToFlat(j, width - i - 1, width)];
				field[squareCoordsToFlat(j, width - i - 1, width)] = b;
			}
			else {
				b = field[squareCoordsToFlat(height - j - 1, i, width)];
				field[squareCoordsToFlat(height - j - 1, i, width)] = field[squareCoordsToFlat(i, j, width)];
				field[squareCoordsToFlat(i, j, width)] = field[squareCoordsToFlat(j, width - i - 1, width)];
				field[squareCoordsToFlat(j, width - i - 1, width)] = field[squareCoordsToFlat(width - i - 1, height - j - 1, width)];
				field[squareCoordsToFlat(width - i - 1, height - j - 1, width)] = b;
			}
		}
	}
	
	if (width % 2 > 0) {
		int center = width / 2;
		if (backward)
		{
			b = field[squareCoordsToFlat(center, 0, width)];
			field[squareCoordsToFlat(center, 0, width)] = field[squareCoordsToFlat(height - 1, center, width)];
			field[squareCoordsToFlat(height - 1, center, width)] = field[squareCoordsToFlat(center, height - 1, width)];
			field[squareCoordsToFlat(center, height - 1, width)] = field[squareCoordsToFlat(0, center, width)];
			field[squareCoordsToFlat(0, center, width)] = b;
		}
		else {
			b = field[squareCoordsToFlat(height - 1, center, width)];
			field[squareCoordsToFlat(height - 1, center, width)] = field[squareCoordsToFlat(center, 0, width)];
			field[squareCoordsToFlat(center, 0, width)] = field[squareCoordsToFlat(0, center, width)];
			field[squareCoordsToFlat(0, center, width)] = field[squareCoordsToFlat(center, height - 1, width)];
			field[squareCoordsToFlat(center, height - 1, width)] = b;
		}
	}
}

void Figure::move(int dx, int dy)
{
	x += dx;
	y += dy;
}

HitCheckResult Figure::CheckHit(GameField * gameField)
{
	bool downHit = false;
	bool leftHit = false;
	bool rightHit = false;

	for(int i = 0; i < width;++i)
		for (int j = 0; j < height; ++j)
		{
			if(field[squareCoordsToFlat(i,j,width)]) {
				if(x + i < 0)
					leftHit = true;

				if (x + i + 1 > gameField->getWidth())
					rightHit = true;

				if (gameField->getValue(x + i, y + j) || gameField->getHeight() < y + j + 1)
					downHit = true;
			}
		}

	HitCheckResult hitCheckResult;
	hitCheckResult.downHit = downHit;
	hitCheckResult.leftHit = leftHit;
	hitCheckResult.rightHit = rightHit;

	return hitCheckResult;
}

void Figure::Paste(GameField * gameField, bool value)
{
	for (int i = 0; i < width; ++i)
		for (int j = 0; j < height; ++j)
		{
			bool fieldValue = field[squareCoordsToFlat(i, j, width)];
			if (fieldValue)
				gameField->setValue(x + i, y + j, value);
		}
}

void Figure::Draw(ID3D11DeviceContext * pImmediateContext, ID3D11Buffer * pVariableBuffer)
{
	for (int lx = 0; lx < width; ++lx)
		for (int ly = 0; ly < height; ++ly)
		{
			if (field[squareCoordsToFlat(lx, ly, width)]) {
				XMMATRIX World = XMMatrixTranslation(topX + squareWidth*(x + lx), topY - squareHeight*(y + ly), 0.0f);

				VariableBuffer vb;
				vb.mWorld = XMMatrixTranspose(World);
				vb.vMeshColor = vBackColor;

				pImmediateContext->UpdateSubresource(pVariableBuffer, 0, NULL, &vb, 0, 0);

				pImmediateContext->VSSetConstantBuffers(1, 1, &pVariableBuffer);
				pImmediateContext->PSSetConstantBuffers(1, 1, &pVariableBuffer);

				pImmediateContext->DrawIndexed(6, 0, 0);

				World = XMMatrixScaling(0.9f, 0.9f, 1.0f);
				World = World * XMMatrixTranslation(topX + squareWidth*(x + lx), topY - squareHeight*(y + ly), 0.0f);

				vb.mWorld = XMMatrixTranspose(World);
				vb.vMeshColor = vFilledColor;
				pImmediateContext->UpdateSubresource(pVariableBuffer, 0, NULL, &vb, 0, 0);

				pImmediateContext->VSSetConstantBuffers(1, 1, &pVariableBuffer);
				pImmediateContext->PSSetConstantBuffers(1, 1, &pVariableBuffer);

				pImmediateContext->DrawIndexed(6, 0, 0);
			}
		}
}

XMFLOAT4 Figure::vBackColor = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
XMFLOAT4 Figure::vFilledColor = XMFLOAT4(0.0f, 0.8f, 0.0f, 1.0f);

int Figure::topX = -9.0f;
int Figure::topY = 5.0f;