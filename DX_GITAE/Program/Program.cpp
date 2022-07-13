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
#include "../Scene/PlaneShootScene.h"

Program::Program()
{
	_scene = make_shared<PlaneShootScene>();
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
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Camera::GetInstance()->SetProjectionBuffer(WIN_WIDTH, WIN_HEIGHT);
	Camera::GetInstance()->SetViewPort(WIN_WIDTH, WIN_HEIGHT);

	ALPHA_STATE->SetState();

	_scene->PreRender();

	_scene->Render();
	EffectManager::GetInstance()->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	_scene->PostRender();
	Camera::GetInstance()->PostRender();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
