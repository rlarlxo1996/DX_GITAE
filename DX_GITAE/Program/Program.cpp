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

Program::Program()
{
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectionBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, -1.0f, 1.0f);

	_projectionBuffer->Set(projectionM);

	_scene = make_shared<EffectScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	_viewBuffer->SetVSBuffer(1);
	_projectionBuffer->SetVSBuffer(2);


	ALPHA_STATE->SetState();

	_scene->PreRender();

	_scene->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	_scene->PostRender();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
