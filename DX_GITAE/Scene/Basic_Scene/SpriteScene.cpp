#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_zelda = make_shared<Zelda>();

	_button = make_shared<Button>();
	_button->SetPosition(CENTER);
	_button->SetScale(Vector2(0.1f, 0.1f));
	_button->SetEvent(std::bind(&SpriteScene::PrevScene, this));
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_zelda->Update();
	_button->Update();
}

void SpriteScene::Render()
{
	_zelda->Render();
}

void SpriteScene::PostRender()
{
	_zelda->PostRender();
	_button->PostRender();
}

void SpriteScene::PrevScene()
{
	SCENE->SetCurSence("Dungreed");
}
