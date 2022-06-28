#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	_texture = make_shared<Texture>(L"Resource/Monster.png");
	_texture->GetTransform()->GetScale() = { 0.7f, 0.7f };

	_col = make_shared<RectCollider>(Vector2(100, 100));
	_col->SetParent(_texture->GetTransform());
}

Monster::~Monster()
{
}

void Monster::Update()
{
	_texture->Update();
	_col->Update();
}

void Monster::Render()
{
	_texture->Render();
	_col->Render();
}
