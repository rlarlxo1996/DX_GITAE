#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<Player>();

	_monster = make_shared<Monster>();
	_monster->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.7f;

	_aim = make_shared<Aim>();

	_button = make_shared<Button>();
	_button->SetPosition(CENTER);
	_button->SetScale(Vector2(0.1f, 0.1f));
	_button->SetEvent(std::bind(&DungreedScene::NextScene, this));
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
			bullet->_isActive = false;
			_monster->_hp--;
			if (_monster->_hp == 0)
			{
				_monster->_isActive = false;
			}
			_monster->GetCollider()->SetColorRed();
			break;
		}
		else
		{
			_monster->GetCollider()->SetColorGreen();
		}
	}

	// UI
	_button->Update();
}

void DungreedScene::Render()
{
	_player->Render();
	_aim->Render();
	_monster->Render();
}

void DungreedScene::PostRender()
{
	//UI
	_button->PostRender();

	ImGui::SliderFloat("PlayerPos X", &_player->GetTransform()->GetPos().x, 0, 1280);
	ImGui::SliderFloat("PlayerPos Y", &_player->GetTransform()->GetPos().y, 0, 720);
}

void DungreedScene::Init()
{
	_player->Init();
}

void DungreedScene::NextScene()
{
	SCENE->SetCurSence("Zelda");
}
