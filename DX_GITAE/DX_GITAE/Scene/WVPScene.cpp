#include "framework.h"
#include "WVPScene.h"

WVPScene::WVPScene()
{
	_texture = make_shared<Texture>(L"Resource/Dia.png");
	_texture2 = make_shared<Texture>(L"Resource/Dia.png");

	_texture->GetTransform()->SetParent(_texture2->GetTransform());

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
	_texture->GetTransform()->GetAngle() += 0.001;
	_texture->GetTransform()->GetPos()._x = 300.0f;

	_texture2->GetTransform()->GetPos()._x -= 0.01;

	_texture->Update();
	_texture2->Update();
}

void WVPScene::Render()
{
	_worldBuffer->SetVSBuffer(0);
	_viewBuffer->SetVSBuffer(1);
	_projectionBuffer->SetVSBuffer(2);

	_texture->Render();
	_texture2->Render();
}
