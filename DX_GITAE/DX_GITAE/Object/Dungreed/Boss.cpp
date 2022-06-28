#include "framework.h"
#include "Boss.h"

Boss::Boss()
{
	_texture = make_shared<Texture>(L"Resource/Boss.png");
	_texture->GetTransform()->GetScale() = { 0.7f, 0.7f };
	_texture->GetTransform()->GetPos() = { 800,500 };

	_col = make_shared<RectCollider>(Vector2(100, 100));
	_col->SetParent(_texture->GetTransform());
}

Boss::~Boss()
{
}

void Boss::Update()
{
	_texture->Update();
	_col->Update();
}

void Boss::Render()
{
	_texture->Render();
	_col->Render();
}
