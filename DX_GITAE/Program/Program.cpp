#include "framework.h"
#include "Program.h"
#include "../Scene/TextureScene.h"
#include "../Scene/WVPScene.h"
#include "../Scene/SolarSystemScene.h"

Program::Program()
{
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectionBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, -1.0f, 1.0f);

	_projectionBuffer->Set(projectionM);
	_projectionBuffer->Update();

	_scene = make_shared<SolarSystemScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	_viewBuffer->Update();

	_scene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	_viewBuffer->SetVSBuffer(1);
	_projectionBuffer->SetVSBuffer(2);

	_scene->Render();

	Device::GetInstance()->Present();
}
