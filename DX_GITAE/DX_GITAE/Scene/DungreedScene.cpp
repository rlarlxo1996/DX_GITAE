#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<Player>();
	_aim = make_shared<Aim>();

	_boss = make_shared<Boss>();
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	for (auto& bullet : _player->GetBullet())
	{
		if (bullet->GetCollider()->IsCollision(_boss->GetCollider()))
		{
			bullet->_isActive = false;
			_boss->_isActive = false;
		}
	}

	_player->Update();
	_aim->Update();

	_boss->Update();
}

void DungreedScene::Render()
{
	_player->Render();
	_aim->Render();

	_boss->Render();
}

void DungreedScene::PostRender()
{
	ImGui::SliderFloat("PlayerPos X", &_player->GetTransform()->GetPos()._x, 0, 1280);
	ImGui::SliderFloat("PlayerPos Y", &_player->GetTransform()->GetPos()._y, 0, 720);
}
