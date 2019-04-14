#pragma once
class DrawingSystem
{
public:
	DrawingSystem() {};
	~DrawingSystem() {};
	virtual bool init() = 0;
	virtual void drawSquare(float x, float y, float width, float height, float r, float g, float b) = 0;
	virtual void beforeDraw() = 0;
	virtual void afterDraw() = 0;
};