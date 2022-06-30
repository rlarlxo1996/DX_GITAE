#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<Player>();
	_monster = make_shared<Monster>();
	_monster->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.7f;

	_aim = make_shared<Aim>();

}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{

	_player->Update();
	_aim->Update();
	_monster->Update();

	for (auto& bullet : _player->GetBullet())
	{
		if (bullet->GetCollider()->IsCollision(_monster->GetCollider()))
		{
			_monster->GetCollider()->SetColorRed();
			break;
		}
		else
		{
			_monster->GetCollider()->SetColorGreen();
		}
	}
}

void DungreedScene::Render()
{
	_player->Render();
	_aim->Render();
	_monster->Render();
}

void DungreedScene::PostRender()
{
	ImGui::SliderFloat("PlayerPos X", &_player->GetTransform()->GetPos().x, 0, 1280);
	ImGui::SliderFloat("PlayerPos Y", &_player->GetTransform()->GetPos().y, 0, 720);
}
