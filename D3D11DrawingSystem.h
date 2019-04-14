#pragma once
#include "DrawingSystem.h"
#include <d3d11.h>
#include <D3DX11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

struct SimpleVertex
{
	XMFLOAT3 Pos;
};

struct ConstantBuffer
{
	XMMATRIX mView;
	XMMATRIX mProjection;
};

struct VariableBuffer
{
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};

class D3D11DrawingSystem :
	public DrawingSystem
{
private:
	HWND hWnd;

	ID3D11Device*           pd3dDevice;
	IDXGISwapChain*         pSwapChain;
	ID3D11DeviceContext*    pImmediateContext;
	ID3D11RenderTargetView* pRenderTargetView;
	ID3D11Buffer*           pVertexBuffer;
	ID3D11Buffer*           pIndexBuffer;
	ID3D11InputLayout*      pVertexLayout;
	ID3D11VertexShader*     pVertexShader;
	ID3D11PixelShader*      pPixelShader;
	ID3D11Buffer*			pConstantBuffer;
	ID3D11Buffer*			pVariableBuffer;

	XMMATRIX                g_World;
	XMMATRIX                g_View;
	XMMATRIX                g_Projection;
public:
	D3D11DrawingSystem(HWND hWnd);
	~D3D11DrawingSystem();
	bool init();
	void drawSquare(float x, float y, float width, float height, float r, float g, float b);
	void beforeDraw();
	void afterDraw();
};