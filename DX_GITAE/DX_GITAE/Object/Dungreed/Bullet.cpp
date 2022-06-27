#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_texture = make_shared<Texture>(L"Resource/Bullet.png");
	_texture->GetTransform()->GetScale() = { 0.1f,0.1f };

	_col = make_shared<CircleCollider>(90);
	_col->SetParent(_texture->GetTransform());
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false)
		return;

	_runTime += DELTA_TIME;

	if (_runTime > _delayTime)
	{
		_runTime = 0.0f;
		_isActive = false;
	}

	_direction.Normalize();
	_texture->GetTransform()->GetPos() += _direction * _speed * DELTA_TIME;

	_texture->Update();
	_col->Update();
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_texture->Render();
	_col->Render();
}

void Bullet::SetDirection(const Vector2& direction)
{
	_direction = direction;
	_texture->GetTransform()->GetAngle() = _direction.Angle();
}
