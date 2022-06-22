#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<Player>();
	_aim = make_shared<Aim>();
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	_player->Update();
	_aim->Update();
}

void DungreedScene::Render()
{
	_player->Render();
	_aim->Render();

	ImGui::SliderFloat("PlayerPos X", &_player->GetTransform()->GetPos()._x, 0, 1280);
	ImGui::SliderFloat("PlayerPos Y", &_player->GetTransform()->GetPos()._y, 0, 720);
}