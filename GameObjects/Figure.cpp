#include "Figure.h"

Figure::Figure()
{
	Reset();
}

Figure::~Figure()
{
}

void Figure::Reset()
{
	model = BaseModel::nextFigure();
	y = 0;
	x = 4;
	orientation = 0;
}

void Figure::Rotate()
{
	orientation = (orientation + 1) % 4;
}

void Figure::move(int dx, int dy)
{
	x += dx;
	y += dy;
}

HitCheckResult Figure::CheckHit(GameField * gameField)
{
	auto width = model->getWidth();
	auto height = model->getHeight();

	bool downHit = false;
	bool leftHit = false;
	bool rightHit = false;

	for(int i = 0; i < width;++i)
		for (int j = 0; j < height; ++j)
		{
			int tx = i;
			int ty = j;
			switch (orientation)
			{
			case 0:
			{
				break;
			}
			case 1:
			{
				tx = j;
				ty = i;
				break;
			}
			case 2:
			{
				tx = width - i - 1;
				ty = height - j - 1;
				break;
			}
			case 3:
			{
				tx = height - j - 1;
				ty = width - i - 1;
				break;
			}
			}
			if (model->getValue(i, j)) {
				if(x + tx < 0)
					leftHit = true;

				if (x + tx + 1 > gameField->getWidth())
					rightHit = true;

				if (gameField->getValue(x + tx, y + ty) || gameField->getHeight() < y + ty + 1)
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
	auto width = model->getWidth();
	auto height = model->getHeight();
	for (int i = 0; i < width; ++i)
		for (int j = 0; j < height; ++j)
		{
			int tx = i;
			int ty = j;
			switch (orientation)
			{
			case 0:
			{
				break;
			}
			case 1:
			{
				tx = j;
				ty = i;
				break;
			}
			case 2:
			{
				tx = width - i - 1;
				ty = height - j - 1;
				break;
			}
			case 3:
			{
				tx = height - j - 1;
				ty = width - i - 1;
				break;
			}
			}

			bool fieldValue = model->getValue(i, j);
			if (fieldValue)
				gameField->setValue(x + tx, y + ty, value);
		}
}
