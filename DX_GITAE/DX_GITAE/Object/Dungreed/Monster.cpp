#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	_quad = make_shared<Quad>(L"Resource/Monster.png");
	_quad->GetTransform()->GetScale() = { 0.7f, 0.7f };

	_col = make_shared<RectCollider>(_quad->GetHalfSize());
	_col->SetParent(_quad->GetTransform());
}

Monster::~Monster()
{
}

void Monster::Update()
{
	_quad->Update();
	_col->Update();
}

void Monster::Render()
{
	_quad->Render();
	_col->Render();
}
