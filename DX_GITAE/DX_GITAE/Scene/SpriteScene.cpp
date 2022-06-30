#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"Resource/zelda.png", Vector2(10, 8));
	_sprite->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_sprite->Update();
}

void SpriteScene::Render()
{
	_sprite->Render();
}

void SpriteScene::PostRender()
{
	ImGui::SliderInt("CurFrameX", &_curFrameX, 0, 9);
	ImGui::SliderInt("CurFrameY", &_curFrameY, 0, 7);

	_sprite->SetCurFrame(Vector2(_curFrameX, _curFrameY));
}
