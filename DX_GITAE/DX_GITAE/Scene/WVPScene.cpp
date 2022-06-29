#include "framework.h"
#include "WVPScene.h"

WVPScene::WVPScene()
{
	_quad = make_shared<Quad>(L"Resource/Dia.png");
	_quad2 = make_shared<Quad>(L"Resource/Dia.png");

	_quad->GetTransform()->SetParent(_quad2->GetTransform());

	_worldBuffer = make_shared<MatrixBuffer>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectionBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectionBuffer->Set(projectionM);
	_projectionBuffer->Update();
	_viewBuffer->Update();
	_worldBuffer->Update();
}

WVPScene::~WVPScene()
{
}

void WVPScene::Update()
{
	// World
	//_worldPos.x = 500;
	XMMATRIX worldS = XMMatrixScaling(1, 1, 1);
	XMMATRIX worldR = XMMatrixRotationZ(0);
	XMMATRIX worldT = XMMatrixTranslation(_worldPos.x, _worldPos.y, 0);
	XMMATRIX worldSRT = worldS * worldR * worldT;
	_worldBuffer->Set(worldSRT);
	_worldBuffer->Update();

	// View
	//_cameraPos.x = 0;
	//_cameraAngle += 0.001;
	XMMATRIX viewS = XMMatrixScaling(1, 1, 1);
	XMMATRIX viewR = XMMatrixRotationZ(_cameraAngle);
	XMMATRIX viewT = XMMatrixTranslation(_cameraPos.x, _cameraPos.y, 0);
	XMMATRIX viewSRT = viewS * viewR * viewT;
	_viewBuffer->Set(viewSRT);
	_viewBuffer->Update();

	// Texture
	_quad->GetTransform()->GetAngle() += 0.001;
	_quad->GetTransform()->GetPos()._x = 300.0f;

	_quad2->GetTransform()->GetPos()._x -= 0.01;

	_quad->Update();
	_quad2->Update();
}

void WVPScene::Render()
{
	_worldBuffer->SetVSBuffer(0);
	_viewBuffer->SetVSBuffer(1);
	_projectionBuffer->SetVSBuffer(2);

	_quad->Render();
	_quad2->Render();
}
