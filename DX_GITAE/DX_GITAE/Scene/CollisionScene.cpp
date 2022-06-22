#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_rectCollider1 = make_shared<RectCollider>(Vector2(50,50));
	_rectCollider2 = make_shared<RectCollider>(Vector2(100,50));
	_rectCollider2->GetPos() = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_rectCollider1->Update();
	_rectCollider2->Update();

	if (_rectCollider1->GetHalfSize()._x >= _rectCollider2->GetHalfSize()._x)
	{
		_rectCollider2->SetColorRed();
	}
	else
	{
		_rectCollider2->SetColorGreen();
	}
}

void CollisionScene::Render()
{
	_rectCollider1->Render();
	_rectCollider2->Render();


}

void CollisionScene::PostRender()
{
	ImGui::SliderFloat("rect1PosX", &_rectCollider1->GetPos()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("rect1PosY", &_rectCollider1->GetPos()._y, 0, WIN_HEIGHT);
}
