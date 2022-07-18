#include "framework.h"
#include "Button.h"

Button::Button()
{
	_quad = make_shared<Quad>(L"Resource/UI/Button.png");
	_collider = make_shared<RectCollider>(_quad->GetHalfSize());
	_collider->SetParent(_quad->GetTransform());

	_quad->GetTransform()->SetParent(Camera::GetInstance()->GetMoveTransform());
}

Button::~Button()
{
}

void Button::Update()
{
	_quad->Update();
	_collider->Update();

	Vector2 temp = MOUSE_POS;
	if (_collider->IsCollision(Camera::GetInstance()->GetMouseWorldPos()))
	{
		_collider->SetColorRed();
	}
	else
	{
		_collider->SetColorGreen();
	}
}

void Button::PostRender()
{
	_quad->Render();
	_collider->Render();

	{
		Vector2 offset;

		float sizeX = _quad->GetHalfSize().x * _quad->GetTransform()->GetScale().x;
		float sizeY = _quad->GetHalfSize().y * _quad->GetTransform()->GetScale().y;

		offset.x = sizeX * 0.5f;
		offset.y = sizeY * 0.5f;

		RECT rect;
		rect.left = _buttonPos.x - sizeX + offset.x;
		rect.top = (WIN_HEIGHT - _buttonPos.y) - sizeY  + offset.y;
		rect.right = _buttonPos.x + sizeX + offset.x;
		rect.bottom = (WIN_HEIGHT - _buttonPos.y) + sizeY + offset.y;

		DirectWrite::GetInstance()->RenderText(StrToWstr(_text), rect);
	}

}

void Button::SetPosition(Vector2 pos)
{
	_quad->GetTransform()->GetPos() = pos;
	_buttonPos = pos;
}

void Button::SetScale(Vector2 scale)
{
	_quad->GetTransform()->GetScale() = scale;
}

void Button::SetText(string text)
{
	_text = text;
}
