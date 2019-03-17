#include "GameField.h"

struct VariableBuffer
{
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};

int _squareCoordsToFlat(int x, int y, int width)
{
	return width*y + x;
}

void GameField::ClearField()
{
	for (int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
			field[_squareCoordsToFlat(x, y, width)] = false;
}

GameField::GameField(int width, int height)
{
	this->width = width;
	this->height = height;

	field = new bool[width*height];

	ClearField();
}

GameField::~GameField()
{
}

bool GameField::getValue(int x, int y)
{
	return field[_squareCoordsToFlat(x, y, width)];
}

void GameField::setValue(int x, int y, bool value)
{
	field[_squareCoordsToFlat(x, y, width)] = value;
}

int GameField::getWidth()
{
	return width;
}

int GameField::getHeight()
{
	return height;
}

void GameField::Draw(ID3D11DeviceContext* pImmediateContext, ID3D11Buffer* pVariableBuffer)
{
	for(int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
		{
			XMMATRIX World = XMMatrixTranslation(topX + 0.4f*x, topY - 0.4f*y, 0.0f);

			VariableBuffer vb;
			vb.mWorld = XMMatrixTranspose(World);
			vb.vMeshColor = vBackColor;

			pImmediateContext->UpdateSubresource(pVariableBuffer, 0, NULL, &vb, 0, 0);

			pImmediateContext->VSSetConstantBuffers(1, 1, &pVariableBuffer);
			pImmediateContext->PSSetConstantBuffers(1, 1, &pVariableBuffer);

			pImmediateContext->DrawIndexed(6, 0, 0);
			
			World = XMMatrixScaling(0.9f, 0.9f, 1.0f);
			World = World * XMMatrixTranslation(topX + 0.4f*x, topY - 0.4f*y, 0.0f);

			vb.mWorld = XMMatrixTranspose(World);
			if(field[_squareCoordsToFlat(x,y,width)])
				vb.vMeshColor = vFilledColor;
			else
				vb.vMeshColor = vEmptyColor;
			pImmediateContext->UpdateSubresource(pVariableBuffer, 0, NULL, &vb, 0, 0);

			pImmediateContext->VSSetConstantBuffers(1, 1, &pVariableBuffer);
			pImmediateContext->PSSetConstantBuffers(1, 1, &pVariableBuffer);

			pImmediateContext->DrawIndexed(6, 0, 0);
		}
}

XMFLOAT4 GameField::vBackColor = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
XMFLOAT4 GameField::vEmptyColor = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
XMFLOAT4 GameField::vFilledColor = XMFLOAT4(0.0f, 0.8f, 0.0f, 1.0f);

int GameField::topX = -9.0f;
int GameField::topY = 5.0f;