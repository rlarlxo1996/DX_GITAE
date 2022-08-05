#include "framework.h"
#include "Program.h"
#include "../Scene/TextureScene.h"
#include "../Scene/WVPScene.h"
#include "../Scene/SolarSystemScene.h"
#include "../Scene/DungreedScene.h"
#include "../Scene/CollisionScene.h"
#include "../Scene/SpriteScene.h"
#include "../Scene/FilterScene.h"
#include "../Scene/EffectScene.h"
#include "../Scene/CameraScene.h"
#include "../Scene/XMLScene.h"
#include "../Scene/PlaneShootScene.h"
#include "../Scene/InstancingScene.h"

Program::Program()
{
	_scene = make_shared<DungreedScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
	EffectManager::GetInstance()->Update();
	Camera::GetInstance()->Update();
}

void Program::Render()
{
	Camera::GetInstance()->SetProjectionBuffer(WIN_WIDTH, WIN_HEIGHT);
	Camera::GetInstance()->SetCameraWorldBuffer();

	_scene->PreRender();

	Device::GetInstance()->SetRTV();
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Camera::GetInstance()->SetViewPort(WIN_WIDTH, WIN_HEIGHT);

	ALPHA_STATE->SetState();

	_scene->Render();
	EffectManager::GetInstance()->Render();

	wstring fps = L"FPS : " + to_wstring((int)Timer::GetInstance()->GetFPS());
	RECT rect = { 0,0,100,100 };

	DirectWrite::GetInstance()->GetDC()->BeginDraw();
	DirectWrite::GetInstance()->RenderText(fps, rect);

	Camera::GetInstance()->SetUiCameraBuffer();
	_scene->PostRender();
	Camera::GetInstance()->PostRender();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	DirectWrite::GetInstance()->GetDC()->EndDraw();
	Device::GetInstance()->Present();
}
